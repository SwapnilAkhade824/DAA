#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

// ============================================================
// Utility Functions
// ============================================================

void indent(int depth) {
    for (int i = 0; i < depth; i++)
        cout << "    ";
}

void printVector(const vector<int>& arr) {
    cout << "[";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1)
            cout << ", ";
    }
    cout << "]";
}

void printRange(const vector<int>& arr, int left, int right) {
    cout << "[";
    for (int i = left; i <= right; i++) {
        cout << arr[i];
        if (i < right)
            cout << ", ";
    }
    cout << "]";
}

// ============================================================
// METHOD 1: MERGING
// ============================================================

double medianUsingMerge(
    const vector<int>& A,
    const vector<int>& B
) {
    cout << "\n========================================\n";
    cout << "METHOD 1: MERGING\n";
    cout << "========================================\n\n";

    int n = A.size();
    int m = B.size();

    int i = 0;
    int j = 0;

    vector<int> merged;

    cout << "A = ";
    printVector(A);
    cout << "\n";

    cout << "B = ";
    printVector(B);
    cout << "\n\n";

    cout << "MERGE PROCESS:\n";
    cout << "----------------------------------------\n";

    while (i < n && j < m) {
        cout << "Compare A[" << i << "] = " << A[i]
             << " and B[" << j << "] = " << B[j] << " -> ";

        if (A[i] <= B[j]) {
            cout << "Take " << A[i] << " from A\n";
            merged.push_back(A[i]);
            i++;
        }
        else {
            cout << "Take " << B[j] << " from B\n";
            merged.push_back(B[j]);
            j++;
        }

        cout << "Current merged array = ";
        printVector(merged);
        cout << "\n\n";
    }

    // Remaining elements of A
    while (i < n) {
        cout << "B exhausted -> Take " << A[i]
             << " from A\n";

        merged.push_back(A[i]);
        i++;
    }

    // Remaining elements of B
    while (j < m) {
        cout << "A exhausted -> Take " << B[j]
             << " from B\n";

        merged.push_back(B[j]);
        j++;
    }

    cout << "\n----------------------------------------\n";
    cout << "FINAL MERGED ARRAY\n";
    cout << "----------------------------------------\n";

    cout << "Merged = ";
    printVector(merged);
    cout << "\n";

    int total = merged.size();
    double median;

    if (total % 2 == 0) {
        int leftMiddle = merged[total / 2 - 1];
        int rightMiddle = merged[total / 2];

        cout << "\nMiddle elements:\n";
        cout << "Left middle  = " << leftMiddle << endl;
        cout << "Right middle = " << rightMiddle << endl;

        median = (leftMiddle + rightMiddle) / 2.0;

        cout << "Median = ("
             << leftMiddle << " + "
             << rightMiddle << ") / 2\n";
    }
    else {
        median = merged[total / 2];

        cout << "\nMiddle element = "
             << merged[total / 2] << endl;
    }

    cout << "Median = "
         << fixed << setprecision(2)
         << median << endl;

    return median;
}

// ============================================================
// METHOD 2: RECURSIVE DIVIDE AND CONQUER
// Median of two sorted arrays of equal size
// ============================================================

double medianDivideConquer(
    const vector<int>& A,
    int aLeft,
    int aRight,
    const vector<int>& B,
    int bLeft,
    int bRight,
    int depth = 0
) {
    int n = aRight - aLeft + 1;

    indent(depth);
    cout << "----------------------------------------\n";

    indent(depth);
    cout << "DIVIDE AND CONQUER - SIZE = "
         << n << endl;

    indent(depth);
    cout << "A = ";
    printRange(A, aLeft, aRight);
    cout << endl;

    indent(depth);
    cout << "B = ";
    printRange(B, bLeft, bRight);
    cout << endl;

    // --------------------------------------------------------
    // Base Case: 1 element
    // --------------------------------------------------------

    if (n == 1) {
        indent(depth);
        cout << "Base case: one element in each array\n";

        double answer =
            (A[aLeft] + B[bLeft]) / 2.0;

        indent(depth);
        cout << "Median = ("
             << A[aLeft] << " + "
             << B[bLeft] << ") / 2 = "
             << answer << endl;

        return answer;
    }

    // --------------------------------------------------------
    // Base Case: 2 elements
    // --------------------------------------------------------

    if (n == 2) {
        int leftMax = max(A[aLeft], B[bLeft]);
        int rightMin = min(A[aRight], B[bRight]);

        double answer =
            (leftMax + rightMin) / 2.0;

        indent(depth);
        cout << "Base case: 2 elements\n";

        indent(depth);
        cout << "max(first elements) = max("
             << A[aLeft] << ", "
             << B[bLeft] << ") = "
             << leftMax << endl;

        indent(depth);
        cout << "min(second elements) = min("
             << A[aRight] << ", "
             << B[bRight] << ") = "
             << rightMin << endl;

        indent(depth);
        cout << "Median = ("
             << leftMax << " + "
             << rightMin << ") / 2 = "
             << answer << endl;

        return answer;
    }

    // --------------------------------------------------------
    // Find medians of both arrays
    // --------------------------------------------------------

    int midA = aLeft + (aRight - aLeft) / 2;
    int midB = bLeft + (bRight - bLeft) / 2;

    int medianA = A[midA];
    int medianB = B[midB];

    indent(depth);
    cout << "Median of A = " << medianA << endl;

    indent(depth);
    cout << "Median of B = " << medianB << endl;

    // --------------------------------------------------------
    // Compare medians
    // --------------------------------------------------------

    if (medianA == medianB) {
        indent(depth);
        cout << "Median A == Median B\n";

        return medianA;
    }

    // --------------------------------------------------------
    // If median A < median B
    // Keep upper half of A and lower half of B
    // --------------------------------------------------------

    if (medianA < medianB) {
        indent(depth);
        cout << medianA
             << " < "
             << medianB << endl;

        indent(depth);
        cout << "Discard lower half of A\n";

        indent(depth);
        cout << "Discard upper half of B\n";

        int newALeft = midA;
        int newBRight = midB;

        cout << endl;

        return medianDivideConquer(
            A,
            newALeft,
            aRight,
            B,
            bLeft,
            newBRight,
            depth + 1
        );
    }

    // --------------------------------------------------------
    // If median A > median B
    // Keep lower half of A and upper half of B
    // --------------------------------------------------------

    indent(depth);
    cout << medianA
         << " > "
         << medianB << endl;

    indent(depth);
    cout << "Discard upper half of A\n";

    indent(depth);
    cout << "Discard lower half of B\n";

    int newARight = midA;
    int newBLeft = midB;

    cout << endl;

    return medianDivideConquer(
        A,
        aLeft,
        newARight,
        B,
        newBLeft,
        bRight,
        depth + 1
    );
}

// ============================================================
// MAIN
// ============================================================

int main() {
    vector<int> A = {
        1, 3, 8, 9, 15
    };

    vector<int> B = {
        7, 11, 18, 19, 21
    };

    cout << "========================================\n";
    cout << "      MEDIAN OF TWO SORTED ARRAYS\n";
    cout << "========================================\n\n";

    cout << "Array A = ";
    printVector(A);
    cout << endl;

    cout << "Array B = ";
    printVector(B);
    cout << "\n";

    // ========================================================
    // METHOD 1
    // ========================================================

    double mergeMedian =
        medianUsingMerge(A, B);

    // ========================================================
    // METHOD 2
    // ========================================================

    cout << "\n\n========================================\n";
    cout << "METHOD 2: DIVIDE AND CONQUER\n";
    cout << "========================================\n\n";

    double divideMedian =
        medianDivideConquer(
            A,
            0,
            A.size() - 1,
            B,
            0,
            B.size() - 1
        );

    // ========================================================
    // FINAL COMPARISON
    // ========================================================

    cout << "\n\n========================================\n";
    cout << "FINAL COMPARISON\n";
    cout << "========================================\n\n";

    cout << "Median using Merge            = "
         << fixed << setprecision(2)
         << mergeMedian << endl;

    cout << "Median using Divide & Conquer = "
         << fixed << setprecision(2)
         << divideMedian << endl;

    cout << "\nTime Complexity:\n";
    cout << "Merging Method          = O(m + n)\n";
    cout << "Divide & Conquer Method = O(log n)\n";

    cout << "\nSpace Complexity:\n";
    cout << "Merging Method          = O(m + n)\n";
    cout << "Divide & Conquer Method = O(log n) recursion stack\n";

    return 0;
}
