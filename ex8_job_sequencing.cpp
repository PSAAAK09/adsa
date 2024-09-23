/*AIM: - To perform Job Sequencing with deadlines using Greedy strategy.
	
THEORY: 
This program defines a Job structure with an ID, deadline, and profit. It sorts the jobs in decreasing order of profit and then schedules them to maximize the total profit by using the Greedy strategy.

PROGRAM:-
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    char id;      // Job Id
    int deadline; // Deadline of job
    int profit;   // Profit if job is completed before or on deadline
};

// Comparator function to sort jobs according to profit
bool comparison(Job a, Job b) {
    return (a.profit > b.profit);
}

// Function to schedule the jobs to maximize profit
void jobSequencing(vector<Job>& jobs) {
    // Sort all jobs according to decreasing order of profit
    sort(jobs.begin(), jobs.end(), comparison);

    int n = jobs.size();
    vector<int> result(n); // To store result (sequence of jobs)
    vector<bool> slot(n, false); // To keep track of free time slots

    // Iterate through all given jobs
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (Note that we start from the last possible slot)
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            // Free slot found
            if (!slot[j]) {
                result[j] = i; // Add this job to result
                slot[j] = true; // Mark this slot as occupied
                break;
            }
        }
    }

    // Print the result
    cout << "Following is the maximum profit sequence of jobs: ";
    for (int i = 0; i < n; i++) {
        if (slot[i]) {
            cout << jobs[result[i]].id << " ";
        }
    }
    cout << endl;
}

int main() {
    vector<Job> jobs = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15} };
    jobSequencing(jobs);
    return 0;
}




