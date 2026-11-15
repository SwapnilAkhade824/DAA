#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Item {
    int value;
    int weight;
    double ratio;
};

int main() {
    vector<Item> items = {
        {60, 10, 0},
        {100, 20, 0},
        {120, 30, 0}
    };

    int capacity = 50;
    double totalValue = 0.0;

    cout << "========================================\n";
    cout << "     FRACTIONAL KNAPSACK - GREEDY\n";
    cout << "========================================\n\n";

    cout << "Knapsack Capacity = " << capacity << " kg\n\n";

    // ------------------------------------------------
    // STEP 1: Calculate value/weight ratio
    // ------------------------------------------------

    cout << "STEP 1: VALUE-TO-WEIGHT RATIO\n";
    cout << "----------------------------------------\n";

    for (int i = 0; i < items.size(); i++) {
        items[i].ratio =
            (double)items[i].value / items[i].weight;

        cout << "Item " << i + 1 << ":\n";
        cout << "Value  = " << items[i].value << endl;
        cout << "Weight = " << items[i].weight << " kg\n";
        cout << "Ratio  = " << items[i].value
             << " / " << items[i].weight
             << " = " << fixed << setprecision(2)
             << items[i].ratio << "\n\n";
    }

    // ------------------------------------------------
    // STEP 2: Sort by descending ratio
    // ------------------------------------------------

    cout << "STEP 2: SORT BY VALUE/WEIGHT RATIO\n";
    cout << "----------------------------------------\n";

    sort(items.begin(), items.end(),
         [](const Item& a, const Item& b) {
             return a.ratio > b.ratio;
         });

    cout << "Order after sorting:\n\n";

    for (int i = 0; i < items.size(); i++) {
        cout << "Position " << i + 1
             << " -> Item with Value = "
             << items[i].value
             << ", Weight = "
             << items[i].weight
             << " kg, Ratio = "
             << fixed << setprecision(2)
             << items[i].ratio << endl;
    }

    cout << "\n";

    // ------------------------------------------------
    // STEP 3: Greedy selection
    // ------------------------------------------------

    cout << "STEP 3: GREEDY SELECTION\n";
    cout << "----------------------------------------\n";

    int remainingCapacity = capacity;

    for (int i = 0; i < items.size(); i++) {
        cout << "\nConsidering Item " << i + 1 << endl;
        cout << "Weight = " << items[i].weight << " kg\n";
        cout << "Value  = " << items[i].value << endl;
        cout << "Ratio  = " << fixed << setprecision(2)
             << items[i].ratio << endl;
        cout << "Remaining Capacity = "
             << remainingCapacity << " kg\n";

        // Complete item can fit
        if (items[i].weight <= remainingCapacity) {
            remainingCapacity -= items[i].weight;
            totalValue += items[i].value;

            cout << "Decision: TAKE COMPLETE ITEM\n";
            cout << "Weight taken = "
                 << items[i].weight << " kg\n";
            cout << "Value added  = "
                 << items[i].value << endl;
        }
        // Only fraction of item can fit
        else {
            double fraction =
                (double)remainingCapacity / items[i].weight;

            double valueTaken =
                items[i].value * fraction;

            totalValue += valueTaken;

            cout << "Decision: TAKE FRACTION OF ITEM\n";
            cout << "Fraction taken = "
                 << fixed << setprecision(2)
                 << fraction << endl;

            cout << "Weight taken   = "
                 << remainingCapacity << " kg\n";

            cout << "Value added    = "
                 << fixed << setprecision(2)
                 << valueTaken << endl;

            remainingCapacity = 0;

            break;
        }

        cout << "Current Total Value = "
             << fixed << setprecision(2)
             << totalValue << endl;

        cout << "Remaining Capacity  = "
             << remainingCapacity << " kg\n";
    }

    // ------------------------------------------------
    // STEP 4: Final result
    // ------------------------------------------------

    cout << "\n========================================\n";
    cout << "FINAL RESULT\n";
    cout << "========================================\n";

    cout << "Maximum Value      = "
         << fixed << setprecision(2)
         << totalValue << endl;

    cout << "Remaining Capacity = "
         << remainingCapacity << " kg\n";

    cout << "\n========================================\n";
    cout << "COMPLEXITY ANALYSIS\n";
    cout << "========================================\n";

    cout << "Ratio Calculation = O(n)\n";
    cout << "Sorting           = O(n log n)\n";
    cout << "Greedy Selection  = O(n)\n";
    cout << "Overall Time      = O(n log n)\n";
    cout << "Auxiliary Space   = O(n)\n";

    return 0;
}
