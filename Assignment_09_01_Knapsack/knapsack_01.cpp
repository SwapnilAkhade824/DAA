#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

void printDPTable(const vector<vector<int>>& dp, int n, int capacity) {
    cout << "\n========================================\n";
    cout << "                DP TABLE\n";
    cout << "========================================\n\n";

    cout << setw(8) << "Item/Cap";

    for (int w = 0; w <= capacity; w++) {
        cout << setw(6) << w;
    }

    cout << "\n";
    cout << string(8 + (capacity + 1) * 6, '-') << "\n";

    for (int i = 0; i <= n; i++) {
        if (i == 0)
            cout << setw(8) << "0";
        else
            cout << setw(8) << ("I" + to_string(i));

        for (int w = 0; w <= capacity; w++) {
            cout << setw(6) << dp[i][w];
        }

        cout << "\n";
    }
}

int main() {
    int n;
    int capacity;

    cout << "========================================\n";
    cout << "        0/1 KNAPSACK - DYNAMIC\n";
    cout << "             PROGRAMMING\n";
    cout << "========================================\n\n";

    // ------------------------------------------------
    // INPUT
    // ------------------------------------------------

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    vector<int> weight(n);
    vector<int> profit(n);

    cout << "\nEnter weight and profit for each item:\n";

    for (int i = 0; i < n; i++) {
        cout << "\nItem " << i + 1 << ":\n";

        cout << "Weight = ";
        cin >> weight[i];

        cout << "Profit = ";
        cin >> profit[i];
    }

    // ------------------------------------------------
    // DISPLAY INPUT
    // ------------------------------------------------

    cout << "\n========================================\n";
    cout << "              INPUT ITEMS\n";
    cout << "========================================\n\n";

    cout << left
         << setw(10) << "Item"
         << setw(10) << "Weight"
         << setw(10) << "Profit" << endl;

    cout << "------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << left
             << setw(10) << i + 1
             << setw(10) << weight[i]
             << setw(10) << profit[i] << endl;
    }

    cout << "\nKnapsack Capacity = "
         << capacity << " kg\n";

    // ------------------------------------------------
    // CREATE DP TABLE
    // ------------------------------------------------

    vector<vector<int>> dp(
        n + 1,
        vector<int>(capacity + 1, 0)
    );

    cout << "\n========================================\n";
    cout << "         DP TABLE CONSTRUCTION\n";
    cout << "========================================\n";

    // ------------------------------------------------
    // FILL DP TABLE
    // ------------------------------------------------

    for (int i = 1; i <= n; i++) {
        cout << "\n----------------------------------------\n";
        cout << "Considering Item " << i
             << " (Weight = " << weight[i - 1]
             << ", Profit = " << profit[i - 1] << ")\n";
        cout << "----------------------------------------\n";

        for (int w = 0; w <= capacity; w++) {
            // Capacity is 0
            if (w == 0) {
                dp[i][w] = 0;

                cout << "DP[" << i << "][" << w
                     << "] = 0 (capacity is 0)\n";

                continue;
            }

            // Item cannot fit
            if (weight[i - 1] > w) {
                dp[i][w] = dp[i - 1][w];

                cout << "DP[" << i << "][" << w << "] : ";
                cout << "Item weight " << weight[i - 1]
                     << " > capacity " << w
                     << " -> DON'T TAKE\n";

                cout << "    DP[" << i << "][" << w << "] = "
                     << dp[i][w] << endl;
            }
            // Item can fit
            else {
                int dontTake = dp[i - 1][w];

                int take =
                    profit[i - 1] +
                    dp[i - 1][w - weight[i - 1]];

                dp[i][w] = max(dontTake, take);

                cout << "DP[" << i << "][" << w << "]\n";
                cout << "    Don't Take = DP["
                     << i - 1 << "][" << w << "]"
                     << " = " << dontTake << endl;

                cout << "    Take       = "
                     << profit[i - 1]
                     << " + DP[" << i - 1
                     << "][" << w - weight[i - 1]
                     << "] = "
                     << take << endl;

                if (take > dontTake) {
                    cout << "    Decision   = TAKE ITEM "
                         << i << endl;
                }
                else {
                    cout << "    Decision   = DON'T TAKE ITEM "
                         << i << endl;
                }

                cout << "    DP[" << i << "][" << w
                     << "] = " << dp[i][w] << endl;
            }
        }
    }

    // ------------------------------------------------
    // DISPLAY DP TABLE
    // ------------------------------------------------

    printDPTable(dp, n, capacity);

    // ------------------------------------------------
    // MAXIMUM PROFIT
    // ------------------------------------------------

    int maximumProfit = dp[n][capacity];

    cout << "\n========================================\n";
    cout << "             MAXIMUM PROFIT\n";
    cout << "========================================\n\n";

    cout << "DP[" << n << "][" << capacity << "] = "
         << maximumProfit << endl;

    // ------------------------------------------------
    // BACKTRACKING
    // ------------------------------------------------

    cout << "\n========================================\n";
    cout << "              BACKTRACKING\n";
    cout << "========================================\n\n";

    int currentCapacity = capacity;
    vector<int> selectedItems;

    for (int i = n; i >= 1; i--) {
        cout << "Checking Item " << i << ":\n";

        cout << "DP[" << i << "]["
             << currentCapacity << "] = "
             << dp[i][currentCapacity] << endl;

        cout << "DP[" << i - 1 << "]["
             << currentCapacity << "] = "
             << dp[i - 1][currentCapacity] << endl;

        // Item selected
        if (dp[i][currentCapacity] !=
            dp[i - 1][currentCapacity]) {
            cout << "Decision -> ITEM " << i
                 << " SELECTED\n";

            selectedItems.push_back(i);

            cout << "Current weight = "
                 << weight[i - 1] << " kg\n";

            currentCapacity -= weight[i - 1];

            cout << "Move to capacity = "
                 << currentCapacity << "\n\n";
        }
        // Item not selected
        else {
            cout << "Decision -> ITEM " << i
                 << " NOT SELECTED\n\n";
        }
    }

    // ------------------------------------------------
    // FINAL RESULT
    // ------------------------------------------------

    cout << "========================================\n";
    cout << "              FINAL RESULT\n";
    cout << "========================================\n\n";

    cout << "Selected Items: ";

    for (int i = selectedItems.size() - 1;
         i >= 0;
         i--) {
        cout << "Item " << selectedItems[i];

        if (i > 0)
            cout << " -> ";
    }

    cout << "\n";

    int totalWeight = 0;

    for (int item : selectedItems) {
        totalWeight += weight[item - 1];
    }

    cout << "Total Weight = "
         << totalWeight << " kg\n";

    cout << "Total Profit = "
         << maximumProfit << endl;

    // ------------------------------------------------
    // COMPLEXITY
    // ------------------------------------------------

    cout << "\n========================================\n";
    cout << "           COMPLEXITY ANALYSIS\n";
    cout << "========================================\n\n";

    cout << "DP Table Construction = O(n * W)\n";
    cout << "Backtracking          = O(n)\n";
    cout << "Overall Time          = O(n * W)\n";
    cout << "Space Complexity      = O(n * W)\n";

    return 0;
}
