#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    string id;
    int deadline;
    int profit;
};

// Print all jobs
void printJobs(const vector<Job>& jobs) {
    for (const Job& job : jobs) {
        cout << job.id
             << " (Deadline = " << job.deadline
             << ", Profit = " << job.profit << ")\n";
    }
}

int main() {
    // ------------------------------------------------
    // INPUT JOBS
    // ------------------------------------------------

    vector<Job> jobs = {
        {"J1", 2, 100},
        {"J2", 1, 50},
        {"J3", 2, 80},
        {"J4", 3, 70},
        {"J5", 1, 60}
    };

    cout << "========================================\n";
    cout << "     JOB SEQUENCING WITH DEADLINES\n";
    cout << "           GREEDY ALGORITHM\n";
    cout << "========================================\n\n";

    cout << "INPUT JOBS\n";
    cout << "----------------------------------------\n";
    printJobs(jobs);

    // ------------------------------------------------
    // STEP 1: SORT BY PROFIT DESCENDING
    // ------------------------------------------------

    sort(jobs.begin(), jobs.end(),
         [](const Job& a, const Job& b) {
             return a.profit > b.profit;
         });

    cout << "\n========================================\n";
    cout << "STEP 1: SORT JOBS BY PROFIT\n";
    cout << "========================================\n\n";

    cout << "Jobs after sorting by profit (descending):\n\n";

    for (int i = 0; i < jobs.size(); i++) {
        cout << i + 1 << ". "
             << jobs[i].id
             << " -> Deadline = "
             << jobs[i].deadline
             << ", Profit = "
             << jobs[i].profit << endl;
    }

    // ------------------------------------------------
    // STEP 2: FIND MAXIMUM DEADLINE
    // ------------------------------------------------

    int maxDeadline = 0;

    for (const Job& job : jobs) {
        if (job.deadline > maxDeadline)
            maxDeadline = job.deadline;
    }

    cout << "\n========================================\n";
    cout << "STEP 2: FIND MAXIMUM DEADLINE\n";
    cout << "========================================\n\n";

    cout << "Maximum Deadline = "
         << maxDeadline << endl;

    // ------------------------------------------------
    // STEP 3: CREATE EMPTY SLOTS
    // ------------------------------------------------

    vector<string> slot(maxDeadline + 1, "");

    cout << "\n========================================\n";
    cout << "STEP 3: CREATE EMPTY SLOTS\n";
    cout << "========================================\n\n";

    cout << "Slots created:\n";

    for (int i = 1; i <= maxDeadline; i++) {
        cout << "Slot " << i << " -> Empty\n";
    }

    // ------------------------------------------------
    // STEP 4: GREEDY JOB SELECTION
    // ------------------------------------------------

    int totalProfit = 0;

    cout << "\n========================================\n";
    cout << "STEP 4: GREEDY JOB SELECTION\n";
    cout << "========================================\n";

    for (const Job& job : jobs) {
        cout << "\n----------------------------------------\n";
        cout << "Considering Job " << job.id << endl;
        cout << "Deadline = " << job.deadline << endl;
        cout << "Profit   = " << job.profit << endl;

        bool assigned = false;

        // Start from deadline and move backward
        for (int j = min(job.deadline, maxDeadline);
             j >= 1;
             j--) {
            cout << "Checking Slot " << j << " -> ";

            // Check whether slot is empty
            if (slot[j] == "") {
                cout << "EMPTY\n";

                slot[j] = job.id;
                totalProfit += job.profit;

                cout << "Assign " << job.id
                     << " to Slot " << j << endl;
                cout << "Profit Added = "
                     << job.profit << endl;

                assigned = true;
                break;
            }
            else {
                cout << "OCCUPIED by "
                     << slot[j] << endl;

                cout << "Move one slot backward...\n";
            }
        }

        if (!assigned) {
            cout << "No available slot before deadline.\n";
            cout << "Job " << job.id
                 << " is NOT selected.\n";
        }
    }

    // ------------------------------------------------
    // STEP 5: DISPLAY FINAL SCHEDULE
    // ------------------------------------------------

    cout << "\n========================================\n";
    cout << "FINAL JOB SCHEDULE\n";
    cout << "========================================\n\n";

    cout << "Execution Order:\n\n";

    for (int i = 1; i <= maxDeadline; i++) {
        if (slot[i] == "") {
            cout << "Slot " << i << " -> EMPTY\n";
        }
        else {
            // Find job details
            for (const Job& job : jobs) {
                if (job.id == slot[i]) {
                    cout << "Slot " << i
                         << " -> " << job.id
                         << " (Deadline = "
                         << job.deadline
                         << ", Profit = "
                         << job.profit << ")\n";

                    break;
                }
            }
        }
    }

    // ------------------------------------------------
    // FINAL RESULT
    // ------------------------------------------------

    cout << "\n========================================\n";
    cout << "FINAL RESULT\n";
    cout << "========================================\n\n";

    cout << "Selected Jobs: ";

    for (int i = 1; i <= maxDeadline; i++) {
        if (slot[i] != "")
            cout << slot[i] << " ";
    }

    cout << "\n";

    cout << "Maximum Total Profit = "
         << totalProfit << endl;

    // ------------------------------------------------
    // COMPLEXITY
    // ------------------------------------------------

    cout << "\n========================================\n";
    cout << "COMPLEXITY ANALYSIS\n";
    cout << "========================================\n\n";

    cout << "Sorting Jobs    = O(n log n)\n";
    cout << "Finding Slots   = O(n^2) worst case\n";
    cout << "Overall Time    = O(n^2)\n";
    cout << "Auxiliary Space = O(n)\n";

    return 0;
}
