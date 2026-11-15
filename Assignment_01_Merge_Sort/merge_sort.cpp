#include <iostream>
#include <vector>
using namespace std;

int comparisons = 0;
int depth = 0;

// Print indentation according to recursion depth
void indent(int d) {
    for (int i = 0; i < d; i++)
        cout << "    ";
}

// Print array from left to right
void printArray(const vector<int>& A, int left, int right) {
    cout << "[";
    for (int i = left; i <= right; i++) {
        cout << A[i];

        if (i < right)
            cout << ", ";
    }
    cout << "]";
}

// Merge two sorted parts
void mergeParts(vector<int>& A, int left, int mid, int right) {
    indent(depth);
    cout << "MERGE: ";
    printArray(A, left, mid);
    cout << " + ";
    printArray(A, mid + 1, right);
    cout << endl;

    vector<int> temp;

    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        comparisons++;

        indent(depth);
        cout << "Compare: " << A[i]
             << " <= " << A[j] << " ? ";

        if (A[i] <= A[j]) {
            cout << "YES -> take " << A[i] << endl;
            temp.push_back(A[i]);
            i++;
        }
        else {
            cout << "NO -> take " << A[j] << endl;
            temp.push_back(A[j]);
            j++;
        }
    }

    // Copy remaining left elements
    while (i <= mid) {
        temp.push_back(A[i]);
        i++;
    }

    // Copy remaining right elements
    while (j <= right) {
        temp.push_back(A[j]);
        j++;
    }

    // Copy back to original array
    for (int k = 0; k < temp.size(); k++)
        A[left + k] = temp[k];

    indent(depth);
    cout << "MERGED -> ";
    printArray(A, left, right);
    cout << "\n\n";
}

// Merge Sort
void mergeSort(vector<int>& A, int left, int right) {
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    indent(depth);
    cout << "DIVIDE: ";
    printArray(A, left, right);
    cout << endl;

    indent(depth);
    cout << "LEFT -> ";
    printArray(A, left, mid);
    cout << endl;

    indent(depth);
    cout << "RIGHT -> ";
    printArray(A, mid + 1, right);
    cout << "\n\n";

    depth++;

    mergeSort(A, left, mid);
    mergeSort(A, mid + 1, right);

    depth--;

    mergeParts(A, left, mid, right);
}

int main() {
    vector<int> A = {38, 27, 43, 3, 9, 82, 10};

    int n = A.size();

    cout << "========================================\n";
    cout << "     MERGE SORT - COMPLETE TRACE\n";
    cout << "========================================\n\n";

    cout << "Original Array: ";
    printArray(A, 0, n - 1);
    cout << "\n\n";

    mergeSort(A, 0, n - 1);

    cout << "========================================\n";
    cout << "FINAL RESULT\n";
    cout << "========================================\n";

    cout << "Sorted Array: ";
    printArray(A, 0, n - 1);
    cout << endl;

    cout << "\nTotal Comparisons = " << comparisons << endl;
    cout << "Time Complexity   = O(n log n)" << endl;
    cout << "Auxiliary Space   = O(n)" << endl;
    cout << "Recursion Stack   = O(log n)" << endl;

    return 0;
}
