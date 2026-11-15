#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
#include <string>
using namespace std;

long long comparisons = 0;
long long swaps = 0;
mt19937 rng(42);

void printArray(const vector<int>& A) {
    cout << "[";
    for (size_t i = 0; i < A.size(); i++) {
        cout << A[i];
        if (i + 1 < A.size())
            cout << ", ";
    }
    cout << "]";
}

void doSwap(vector<int>& A, int i, int j) {
    if (i == j)
        return;
    swaps++;
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

// Standard Lomuto partition using A[high] as pivot
int partitionLastPivot(vector<int>& A, int low, int high, bool trace) {
    int pivot = A[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparisons++;
        if (A[j] <= pivot) {
            i++;
            doSwap(A, i, j);
        }
    }
    doSwap(A, i + 1, high);

    if (trace) {
        cout << "  Partition [" << low << ".." << high
             << "] pivot=" << pivot
             << " -> pos " << (i + 1) << " : ";
        printArray(A);
        cout << "\n";
    }
    return i + 1;
}

// Randomized partition: pick random index in [low, high], swap with A[high]
int partitionRandomPivot(vector<int>& A, int low, int high, bool trace) {
    uniform_int_distribution<int> dist(low, high);
    int randomIndex = dist(rng);

    if (trace) {
        cout << "  Random pivot index=" << randomIndex
             << " (value=" << A[randomIndex] << ") in ["
             << low << ".." << high << "]\n";
    }

    doSwap(A, randomIndex, high);
    return partitionLastPivot(A, low, high, trace);
}

void randomizedQuickSort(vector<int>& A, int low, int high, bool trace = true) {
    if (low >= high)
        return;

    int pivotPos = partitionRandomPivot(A, low, high, trace);
    randomizedQuickSort(A, low, pivotPos - 1, trace);
    randomizedQuickSort(A, pivotPos + 1, high, trace);
}

void ordinaryQuickSort(vector<int>& A, int low, int high, bool trace = true) {
    if (low >= high)
        return;

    int pivotPos = partitionLastPivot(A, low, high, trace);
    ordinaryQuickSort(A, low, pivotPos - 1, trace);
    ordinaryQuickSort(A, pivotPos + 1, high, trace);
}

struct TestResult {
    string name;
    long long randComp;
    long long randSwap;
    long long ordComp;
    long long ordSwap;
};

TestResult runTestCase(const string& name, const vector<int>& input) {
    TestResult res;
    res.name = name;

    // 1. Randomized Quick Sort
    vector<int> aRand = input;
    comparisons = 0;
    swaps = 0;
    cout << "------------------------------------------------------------\n";
    cout << "TEST CASE: " << name << "\n";
    cout << "Input: ";
    printArray(input);
    cout << "\n\n";

    cout << "[1] Randomized Quick Sort (Random Pivot):\n";
    randomizedQuickSort(aRand, 0, (int)aRand.size() - 1, true);
    res.randComp = comparisons;
    res.randSwap = swaps;
    cout << "  Sorted     : ";
    printArray(aRand);
    cout << "\n  Comparisons: " << res.randComp
         << " | Swaps: " << res.randSwap << "\n\n";

    // 2. Ordinary Quick Sort (Last Element Pivot)
    vector<int> aOrd = input;
    comparisons = 0;
    swaps = 0;
    cout << "[2] Ordinary Quick Sort (Last Element Pivot):\n";
    ordinaryQuickSort(aOrd, 0, (int)aOrd.size() - 1, true);
    res.ordComp = comparisons;
    res.ordSwap = swaps;
    cout << "  Sorted     : ";
    printArray(aOrd);
    cout << "\n  Comparisons: " << res.ordComp
         << " | Swaps: " << res.ordSwap << "\n\n";

    return res;
}

int main() {
    cout << "============================================================\n";
    cout << "     RANDOMIZED QUICK SORT vs ORDINARY QUICK SORT\n";
    cout << "============================================================\n\n";

    vector<pair<string, vector<int>>> tests = {
        {"Unsorted Array",       {24, 9, 29, 14, 19, 27}},
        {"Sorted Array",         {9, 14, 19, 24, 27, 29}},
        {"Reverse-Sorted Array", {29, 27, 24, 19, 14, 9}},
        {"Duplicate Elements",   {5, 2, 5, 1, 2}}
    };

    vector<TestResult> results;
    for (const auto& t : tests) {
        results.push_back(runTestCase(t.first, t.second));
    }

    // Comparison Summary Table
    cout << "============================================================\n";
    cout << "COMPARISON SUMMARY\n";
    cout << "============================================================\n";
    cout << left << setw(22) << "Test Case"
         << setw(12) << "Rand Comp"
         << setw(12) << "Rand Swap"
         << setw(12) << "Ord Comp"
         << setw(12) << "Ord Swap" << "\n";
    cout << string(68, '-') << "\n";

    for (const auto& r : results) {
        cout << left << setw(22) << r.name
             << setw(12) << r.randComp
             << setw(12) << r.randSwap
             << setw(12) << r.ordComp
             << setw(12) << r.ordSwap << "\n";
    }

    cout << "\n============================================================\n";
    cout << "TIME & SPACE COMPLEXITY ANALYSIS\n";
    cout << "============================================================\n";
    cout << "Randomized Quick Sort (Las Vegas Algorithm):\n";
    cout << "  - Best Case Time     : O(n log n)\n";
    cout << "  - Expected/Avg Time  : O(n log n)\n";
    cout << "  - Worst Case Time    : O(n^2) [probability -> 0 for large n]\n";
    cout << "  - Space Complexity   : O(log n) expected stack, O(n) worst\n\n";
    cout << "Ordinary Quick Sort (Fixed Last-Element Pivot):\n";
    cout << "  - Best Case Time     : O(n log n)\n";
    cout << "  - Average Case Time  : O(n log n)\n";
    cout << "  - Worst Case Time    : O(n^2) [triggered on sorted/reverse-sorted]\n";
    cout << "  - Space Complexity   : O(log n) avg stack, O(n) worst\n";

    return 0;
}
