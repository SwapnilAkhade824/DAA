#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

vector<int> naiveStringMatch(const string& text, const string& pattern) {
    int n = (int)text.size();
    int m = (int)pattern.size();
    vector<int> matches;

    cout << "Text    : " << text << " (n = " << n << ")\n";
    cout << "Pattern : " << pattern << " (m = " << m << ")\n\n";

    if (m == 0 || m > n) {
        cout << "No valid positions to check.\n";
        return matches;
    }

    cout << left << setw(12) << "Position"
         << setw(14) << "Substring"
         << "Result\n";
    cout << string(38, '-') << "\n";

    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }

        string sub = text.substr(i, m);
        bool matched = (j == m);

        cout << left << setw(12) << i
             << setw(14) << sub
             << (matched ? "Match" : "No match") << "\n";

        if (matched) {
            matches.push_back(i);
        }
    }

    return matches;
}

int main() {
    cout << "========================================\n";
    cout << "     NAIVE STRING MATCHING ALGORITHM\n";
    cout << "========================================\n\n";

    string text = "AABAACAADAABAABA";
    string pattern = "AABA";

    vector<int> matches = naiveStringMatch(text, pattern);

    cout << "\n========================================\n";
    cout << "FINAL RESULT\n";
    cout << "========================================\n";
    if (matches.empty()) {
        cout << "Pattern not found in the text.\n";
    } else {
        for (int idx : matches) {
            cout << "Pattern found at index: " << idx << "\n";
        }
    }

    cout << "\n========================================\n";
    cout << "COMPLEXITY ANALYSIS\n";
    cout << "========================================\n";
    cout << "Best Case Time    : O(n)\n";
    cout << "Average Case Time : O(n * m)\n";
    cout << "Worst Case Time   : O(n * m)\n";
    cout << "Space Complexity  : O(1)\n";

    return 0;
}
