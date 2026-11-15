#include <iostream>
#include <vector>
using namespace std;

int iterativeComparisons = 0;
int recursiveComparisons = 0;
int recursiveDepth = 0;

// Print the array
void printArray(const vector<int>& A) {
    cout << "[";
    for (int i = 0; i < A.size(); i++) {
        cout << A[i];
        if (i < A.size() - 1)
            cout << ", ";
    }
    cout << "]";
}

// Print indentation for recursive calls
void indent(int d) {
    for (int i = 0; i < d; i++)
        cout << "    ";
}

// ============================================================
// ITERATIVE BINARY SEARCH
// ============================================================

int binarySearchIterative(const vector<int>& A, int key) {
    int low = 0;
    int high = A.size() - 1;

    cout << "\n----------------------------------------\n";
    cout << "ITERATIVE BINARY SEARCH\n";
    cout << "Key = " << key << endl;
    cout << "----------------------------------------\n";

    while (low <= high) {
        int mid = low + (high - low) / 2;

        iterativeComparisons++;

        cout << "Step " << iterativeComparisons << ":\n";
        cout << "low = " << low
             << ", mid = " << mid
             << ", high = " << high << endl;

        cout << "A[mid] = A[" << mid << "] = "
             << A[mid] << endl;

        cout << "Compare " << A[mid]
             << " with " << key << " -> ";

        if (A[mid] == key) {
            cout << "EQUAL\n";
            cout << "Key FOUND at index " << mid << endl;
            return mid;
        }

        if (A[mid] < key) {
            cout << A[mid] << " < " << key << endl;
            cout << "Search RIGHT half\n";
            low = mid + 1;
        }
        else {
            cout << A[mid] << " > " << key << endl;
            cout << "Search LEFT half\n";
            high = mid - 1;
        }

        cout << endl;
    }

    cout << "Key NOT FOUND\n";

    return -1;
}

// ============================================================
// RECURSIVE BINARY SEARCH
// ============================================================

int binarySearchRecursive(
    const vector<int>& A,
    int low,
    int high,
    int key
) {
    if (low > high) {
        indent(recursiveDepth);
        cout << "low > high -> Search space empty\n";
        return -1;
    }

    int mid = low + (high - low) / 2;

    recursiveComparisons++;

    indent(recursiveDepth);
    cout << "Step " << recursiveComparisons << ":\n";

    indent(recursiveDepth);
    cout << "low = " << low
         << ", mid = " << mid
         << ", high = " << high << endl;

    indent(recursiveDepth);
    cout << "A[mid] = A[" << mid << "] = "
         << A[mid] << endl;

    indent(recursiveDepth);
    cout << "Compare " << A[mid]
         << " with " << key << " -> ";

    if (A[mid] == key) {
        cout << "EQUAL\n";

        indent(recursiveDepth);
        cout << "Key FOUND at index " << mid << endl;

        return mid;
    }

    if (A[mid] < key) {
        cout << A[mid] << " < " << key << endl;

        indent(recursiveDepth);
        cout << "Search RIGHT half\n\n";

        recursiveDepth++;

        int result = binarySearchRecursive(
            A,
            mid + 1,
            high,
            key
        );

        recursiveDepth--;

        return result;
    }

    cout << A[mid] << " > " << key << endl;

    indent(recursiveDepth);
    cout << "Search LEFT half\n\n";

    recursiveDepth++;

    int result = binarySearchRecursive(
        A,
        low,
        mid - 1,
        key
    );

    recursiveDepth--;

    return result;
}

// ============================================================
// MAIN
// ============================================================

int main() {
    vector<int> A = {
        2, 5, 8, 12, 16,
        23, 38, 56, 72, 91
    };

    cout << "========================================\n";
    cout << "             BINARY SEARCH\n";
    cout << "========================================\n\n";

    cout << "Sorted Array: ";
    printArray(A);
    cout << "\n";

    // ========================================================
    // KEY = 23
    // ========================================================

    iterativeComparisons = 0;

    int result1 = binarySearchIterative(A, 23);

    cout << "\nTotal comparisons for key 23 = "
         << iterativeComparisons << endl;

    // ========================================================
    // KEY = 40
    // ========================================================

    iterativeComparisons = 0;

    int result2 = binarySearchIterative(A, 40);

    cout << "\nTotal comparisons for key 40 = "
         << iterativeComparisons << endl;

    // ========================================================
    // RECURSIVE SEARCH - 23
    // ========================================================

    recursiveComparisons = 0;
    recursiveDepth = 0;

    cout << "\n\n========================================\n";
    cout << "RECURSIVE BINARY SEARCH - KEY 23\n";
    cout << "========================================\n\n";

    int recursiveResult1 =
        binarySearchRecursive(
            A,
            0,
            A.size() - 1,
            23
        );

    cout << "\nRecursive comparisons for key 23 = "
         << recursiveComparisons << endl;

    // ========================================================
    // RECURSIVE SEARCH - 40
    // ========================================================

    recursiveComparisons = 0;
    recursiveDepth = 0;

    cout << "\n========================================\n";
    cout << "RECURSIVE BINARY SEARCH - KEY 40\n";
    cout << "========================================\n\n";

    int recursiveResult2 =
        binarySearchRecursive(
            A,
            0,
            A.size() - 1,
            40
        );

    cout << "\nRecursive comparisons for key 40 = "
         << recursiveComparisons << endl;

    // ========================================================
    // COMPLEXITY
    // ========================================================

    cout << "\n\n========================================\n";
    cout << "COMPLEXITY ANALYSIS\n";
    cout << "========================================\n";

    cout << "\nRecursive Binary Search:\n";
    cout << "Recurrence       = T(n) = T(n/2) + 1\n";
    cout << "Time Complexity  = O(log n)\n";
    cout << "Space Complexity = O(log n)\n";

    cout << "\nIterative Binary Search:\n";
    cout << "Recurrence       = T(n) = T(n/2) + 1\n";
    cout << "Time Complexity  = O(log n)\n";
    cout << "Space Complexity = O(1)\n";

    return 0;
}
