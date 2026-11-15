#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Compute initial ASCII-sum hash for s[0..m-1]
int computeHash(const string& s, int m) {
    int h = 0;
    for (int i = 0; i < m; i++) {
        h += (int)(unsigned char)s[i];
    }
    return h;
}

// Rabin-Karp pattern search using rolling ASCII-sum hash
vector<int> rabinKarpSearch(const string& text, const string& pattern) {
    int n = (int)text.size();
    int m = (int)pattern.size();
    vector<int> matches;

    cout << "Text    : " << text << " (n = " << n << ")\n";
    cout << "Pattern : " << pattern << " (m = " << m << ")\n\n";

    if (m == 0 || m > n) {
        cout << "No valid windows to check.\n";
        return matches;
    }

    // Step 1: Calculate hash value of the pattern
    int patternHash = computeHash(pattern, m);
    cout << "Pattern hash h(\"" << pattern << "\") = ";
    for (int i = 0; i < m; i++) {
        cout << (int)(unsigned char)pattern[i];
        if (i + 1 < m) cout << " + ";
    }
    cout << " = " << patternHash << "\n\n";

    // Step 2: Calculate hash value of the first text window
    int windowHash = computeHash(text, m);

    cout << "Sliding Windows & Rolling Hash Trace:\n";
    cout << "----------------------------------------\n";

    for (int i = 0; i <= n - m; i++) {
        string window = text.substr(i, m);
        cout << "Window " << i << " (\"" << window << "\"): hash = " << windowHash;

        // Step 3: Compare both hash values
        if (windowHash == patternHash) {
            cout << " == " << patternHash << " -> Hash MATCH! Verifying characters... ";

            // Step 4: Verify actual characters
            bool exactMatch = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    exactMatch = false;
                    break;
                }
            }

            if (exactMatch) {
                cout << "PATTERN FOUND at index " << i << "\n";
                matches.push_back(i);
            } else {
                cout << "SPURIOUS HIT (characters differ)\n";
            }
        } else {
            cout << " != " << patternHash << " -> No match\n";
        }

        // Step 5: Use rolling hash for the next window
        if (i < n - m) {
            int outgoing = (int)(unsigned char)text[i];
            int incoming = (int)(unsigned char)text[i + m];
            int nextHash = windowHash - outgoing + incoming;
            cout << "  Rolling hash: " << windowHash
                 << " - ASCII('" << text[i] << "'=" << outgoing << ")"
                 << " + ASCII('" << text[i + m] << "'=" << incoming << ")"
                 << " = " << nextHash << "\n";
            windowHash = nextHash;
        }
    }

    return matches;
}

int main() {
    cout << "========================================\n";
    cout << "      RABIN-KARP PATTERN SEARCHING\n";
    cout << "========================================\n\n";

    // Test Case 1: Example from Rabin Karp Concept.pdf
    cout << "TEST CASE 1 (Concept PDF Example):\n";
    cout << "========================================\n";
    vector<int> res1 = rabinKarpSearch("ABABCA", "ABC");
    cout << "\nOccurrences found: ";
    if (res1.empty()) cout << "None";
    for (size_t i = 0; i < res1.size(); i++) {
        cout << res1[i] << (i + 1 < res1.size() ? ", " : "");
    }
    cout << "\n\n";

    // Test Case 2: Multiple occurrences
    cout << "TEST CASE 2 (Multiple Occurrences):\n";
    cout << "========================================\n";
    vector<int> res2 = rabinKarpSearch("AABAACAADAABAABA", "AABA");
    cout << "\nOccurrences found: ";
    if (res2.empty()) cout << "None";
    for (size_t i = 0; i < res2.size(); i++) {
        cout << res2[i] << (i + 1 < res2.size() ? ", " : "");
    }
    cout << "\n\n";

    cout << "========================================\n";
    cout << "COMPLEXITY ANALYSIS\n";
    cout << "========================================\n";
    cout << "Average / Best Case Time : O(n + m)\n";
    cout << "Worst Case Time          : O(n * m) (many hash collisions / spurious hits)\n";
    cout << "Space Complexity         : O(1) auxiliary\n";

    return 0;
}
