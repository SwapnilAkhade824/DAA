#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int nodesExplored = 0;
int prunedNodes = 0;

void printSubset(const vector<int>& subset) {
    cout << "{ ";
    for (int x : subset) {
        cout << x << " ";
    }
    cout << "}";
}

void sumOfSubsetsBB(
    const vector<int>& arr,
    int idx,
    int currentSum,
    int remainingSum,
    int target,
    vector<int>& currentSubset,
    vector<vector<int>>& solutions
) {
    nodesExplored++;

    // Solution found
    if (currentSum == target) {
        solutions.push_back(currentSubset);
        cout << "  [SOLUTION] ";
        printSubset(currentSubset);
        cout << " -> sum = " << currentSum << "\n";
        return;
    }

    // Bound 1: currentSum exceeds target
    if (currentSum > target) {
        prunedNodes++;
        cout << "  [PRUNE]    ";
        printSubset(currentSubset);
        cout << " -> sum (" << currentSum << ") > target (" << target << ")\n";
        return;
    }

    // Bound 2: even with all remaining elements, cannot reach target
    if (currentSum + remainingSum < target) {
        prunedNodes++;
        cout << "  [PRUNE]    ";
        printSubset(currentSubset);
        cout << " -> sum + remaining (" << currentSum << " + " << remainingSum
             << " = " << (currentSum + remainingSum) << ") < target (" << target << ")\n";
        return;
    }

    if (idx >= (int)arr.size()) {
        return;
    }

    int nextRemaining = remainingSum - arr[idx];

    // Branch 1: Include arr[idx]
    currentSubset.push_back(arr[idx]);
    sumOfSubsetsBB(arr, idx + 1, currentSum + arr[idx], nextRemaining, target, currentSubset, solutions);
    currentSubset.pop_back();

    // Branch 2: Exclude arr[idx]
    sumOfSubsetsBB(arr, idx + 1, currentSum, nextRemaining, target, currentSubset, solutions);
}

int main() {
    cout << "========================================\n";
    cout << "  SUM OF SUBSETS - BRANCH AND BOUND\n";
    cout << "========================================\n\n";

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        totalSum += arr[i];
    }

    int target;
    cout << "Enter target sum: ";
    cin >> target;

    sort(arr.begin(), arr.end());

    cout << "\nSorted Set : ";
    printSubset(arr);
    cout << "\nTarget Sum : " << target << "\n";
    cout << "Total Sum  : " << totalSum << "\n\n";

    cout << "========================================\n";
    cout << "BRANCH AND BOUND TRACE\n";
    cout << "========================================\n";

    vector<int> currentSubset;
    vector<vector<int>> solutions;

    sumOfSubsetsBB(arr, 0, 0, totalSum, target, currentSubset, solutions);

    cout << "\n========================================\n";
    cout << "Subsets with sum " << target << ":\n";
    cout << "========================================\n";
    if (solutions.empty()) {
        cout << "No subset found with sum " << target << ".\n";
    } else {
        for (const auto& sol : solutions) {
            printSubset(sol);
            cout << "\n";
        }
    }

    cout << "\nNodes Explored : " << nodesExplored << "\n";
    cout << "Branches Pruned: " << prunedNodes << "\n";

    cout << "\n========================================\n";
    cout << "COMPLEXITY ANALYSIS\n";
    cout << "========================================\n";
    cout << "Worst-case Time  : O(2^n)\n";
    cout << "Worst-case Space : O(n)\n";

    return 0;
}
