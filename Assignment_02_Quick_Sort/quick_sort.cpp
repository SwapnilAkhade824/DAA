#include <iostream>
#include <vector>
using namespace std;

int comparisons = 0;
int swaps = 0;
int depth = 0;

// Print indentation
void indent(int d) {
    for (int i = 0; i < d; i++)
        cout << "    ";
}

// Print complete array
void printArray(const vector<int>& A) {
    cout << "[";
    for (int i = 0; i < A.size(); i++) {
        cout << A[i];

        if (i < A.size() - 1)
            cout << ", ";
    }
    cout << "]";
}

// Print only a part of array
void printPart(const vector<int>& A, int low, int high) {
    cout << "[";
    for (int i = low; i <= high; i++) {
        cout << A[i];

        if (i < high)
            cout << ", ";
    }
    cout << "]";
}

// Perform actual swap
void doSwap(vector<int>& A, int i, int j) {
    if (i == j)
        return;

    swaps++;

    indent(depth);
    cout << "SWAP: " << A[i]
         << " <-> " << A[j] << endl;

    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

// Partition using last element as pivot
int partitionArray(vector<int>& A, int low, int high) {
    int pivot = A[high];

    indent(depth);
    cout << "----------------------------------------\n";

    indent(depth);
    cout << "PARTITION: ";
    printPart(A, low, high);
    cout << endl;

    indent(depth);
    cout << "Pivot = " << pivot << " (last element)" << endl;

    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparisons++;

        indent(depth);
        cout << "Compare: " << A[j]
             << " <= " << pivot << " ? ";

        if (A[j] <= pivot) {
            cout << "YES" << endl;

            i++;

            if (i != j)
                doSwap(A, i, j);
            else {
                indent(depth);
                cout << "No swap needed" << endl;
            }
        }
        else {
            cout << "NO" << endl;
        }

        indent(depth);
        cout << "Current array: ";
        printArray(A);
        cout << endl;
    }

    // Place pivot in correct position
    indent(depth);
    cout << "Place pivot " << pivot << " at position "
         << i + 1 << endl;

    if (i + 1 != high)
        doSwap(A, i + 1, high);

    indent(depth);
    cout << "AFTER PARTITION: ";
    printArray(A);
    cout << endl;

    indent(depth);
    cout << "Pivot final position = " << i + 1 << endl;

    indent(depth);
    cout << "----------------------------------------\n\n";

    return i + 1;
}

// Quick Sort
void quickSort(vector<int>& A, int low, int high) {
    if (low >= high)
        return;

    indent(depth);
    cout << "QUICKSORT ON: ";
    printPart(A, low, high);
    cout << endl;

    depth++;

    int pivotPosition = partitionArray(A, low, high);

    indent(depth);
    cout << "LEFT  PART: ";

    if (low <= pivotPosition - 1)
        printPart(A, low, pivotPosition - 1);
    else
        cout << "[]";

    cout << endl;

    indent(depth);
    cout << "RIGHT PART: ";

    if (pivotPosition + 1 <= high)
        printPart(A, pivotPosition + 1, high);
    else
        cout << "[]";

    cout << "\n\n";

    quickSort(A, low, pivotPosition - 1);
    quickSort(A, pivotPosition + 1, high);

    depth--;
}

void runQuickSort(vector<int> A, string title) {
    comparisons = 0;
    swaps = 0;
    depth = 0;

    int n = A.size();

    cout << "\n========================================\n";
    cout << title << endl;
    cout << "========================================\n\n";

    cout << "Original Array: ";
    printArray(A);
    cout << "\n\n";

    quickSort(A, 0, n - 1);

    cout << "========================================\n";
    cout << "FINAL RESULT\n";
    cout << "========================================\n";

    cout << "Sorted Array: ";
    printArray(A);
    cout << endl;

    cout << "Total Comparisons = " << comparisons << endl;
    cout << "Total Swaps       = " << swaps << endl;
}

int main() {
    // Original input
    vector<int> A = {24, 9, 29, 14, 19, 27};

    runQuickSort(A, "QUICK SORT - ORIGINAL INPUT");

    // Already sorted input
    vector<int> B = {9, 14, 19, 24, 27, 29};

    runQuickSort(B, "QUICK SORT - ALREADY SORTED INPUT");

    cout << "\n========================================\n";
    cout << "COMPLEXITY ANALYSIS\n";
    cout << "========================================\n";

    cout << "Best Case     = O(n log n)" << endl;
    cout << "Average Case  = O(n log n)" << endl;
    cout << "Worst Case    = O(n^2)" << endl;
    cout << "Average Space = O(log n)" << endl;
    cout << "Worst Space   = O(n)" << endl;

    return 0;
}
