#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Result {
    int maximum;
    int minimum;
};

int comparisons = 0;
int depth = 0;

// Print indentation according to recursion level
void indent(int d) {
    for (int i = 0; i < d; i++)
        cout << "    ";
}

Result findMaxMin(const vector<int>& A, int low, int high) {
    indent(depth);
    cout << "Divide: [" << low << " ... " << high << "]" << endl;

    // Base case: one element
    if (low == high) {
        indent(depth);
        cout << "Single element -> " << A[low] << endl;

        return {A[low], A[low]};
    }

    // Base case: two elements
    if (high == low + 1) {
        comparisons++;

        indent(depth);
        cout << "Compare: " << A[low] << " > " << A[high] << " ? ";

        if (A[low] > A[high]) {
            cout << "YES" << endl;

            indent(depth);
            cout << "Result -> Max = " << A[low]
                 << ", Min = " << A[high] << endl;

            return {A[low], A[high]};
        } else {
            cout << "NO" << endl;

            indent(depth);
            cout << "Result -> Max = " << A[high]
                 << ", Min = " << A[low] << endl;

            return {A[high], A[low]};
        }
    }

    // Divide
    int mid = (low + high) / 2;

    depth++;
    Result left = findMaxMin(A, low, mid);
    Result right = findMaxMin(A, mid + 1, high);
    depth--;

    // Combine maximum
    comparisons++;
    indent(depth);
    cout << "Compare Max: " << left.maximum
         << " > " << right.maximum << " ? ";

    int maximum;
    if (left.maximum > right.maximum) {
        cout << "YES" << endl;
        maximum = left.maximum;
    } else {
        cout << "NO" << endl;
        maximum = right.maximum;
    }

    // Combine minimum
    comparisons++;
    indent(depth);
    cout << "Compare Min: " << left.minimum
         << " < " << right.minimum << " ? ";

    int minimum;
    if (left.minimum < right.minimum) {
        cout << "YES" << endl;
        minimum = left.minimum;
    } else {
        cout << "NO" << endl;
        minimum = right.minimum;
    }

    indent(depth);
    cout << "Combine -> Max = " << maximum
         << ", Min = " << minimum << endl;

    return {maximum, minimum};
}

int main() {
    vector<int> A = {70, 250, 50, 80, 140, 12, 14};

    int n = A.size();

    cout << "========================================\n";
    cout << "   MAX-MIN USING DIVIDE AND CONQUER\n";
    cout << "========================================\n\n";

    cout << "Array: ";
    for (int x : A)
        cout << x << " ";
    cout << "\n\n";

    Result ans = findMaxMin(A, 0, n - 1);

    cout << "\n========================================\n";
    cout << "FINAL RESULT\n";
    cout << "========================================\n";

    cout << "Maximum = " << ans.maximum << endl;
    cout << "Minimum = " << ans.minimum << endl;

    cout << "\nTotal Comparisons (D&C)   = "
         << comparisons << endl;

    int straightforward = 2 * (n - 1);

    cout << "Straight Scan Comparisons = "
         << straightforward << endl;

    cout << "Comparisons Saved         = "
         << straightforward - comparisons << endl;

    cout << "\nTime Complexity  = O(n) = " << "O(" << A.size() << ")" << endl;
    cout << "Space Complexity = O(log n) = " << "O(" << log2(A.size()) << ")"
         << endl;

    return 0;
}
