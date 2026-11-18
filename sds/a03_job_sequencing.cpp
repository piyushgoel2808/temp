/*
 * A3. Write a program to find solution for job sequencing with deadlines problem.
 * Subject: Design and Analysis of Algorithms Lab (MCA-201)
 * Name: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem, Sec-B
 */

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_JOBS 100

// Job structure to hold job details
struct Job
{
    int id;       // Job ID
    int profit;   // Profit associated with the job
    int deadline; // Deadline of the job
};

// Function to compare jobs based on profit (for sorting)
void swapJobs(Job *a, Job *b)
{
    Job temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort jobs based on profit in descending order
void sortJobs(Job jobs[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (jobs[j].profit < jobs[j + 1].profit)
            {
                swapJobs(&jobs[j], &jobs[j + 1]);
            }
        }
    }
}

// Function to perform job sequencing with deadlines
void jobSequencing(Job jobs[], int n)
{
    // Sort jobs based on profit
    sortJobs(jobs, n);

    // To keep track of free time slots
    int result[MAX_JOBS];
    bool slot[MAX_JOBS];

    // Initialize all slots to free
    for (int i = 0; i < n; i++)
        slot[i] = false;

    // Iterate through all jobs
    for (int i = 0; i < n; i++)
    {
        // Find a free slot for this job (from its deadline to the start)
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--)
        {
            // If the slot is free
            if (!slot[j])
            {
                slot[j] = true;  // Mark this slot as occupied
                result[j] = i;   // Store the job index in the result
                break;
            }
        }
    }

    // Print the result
    cout << "Scheduled Jobs:\n";
    int totalProfit = 0;
    for (int i = 0; i < n; i++)
    {
        if (slot[i])
        {
            cout << "Job ID: " << jobs[result[i]].id << " (Profit: " << jobs[result[i]].profit << ")\n";
            totalProfit += jobs[result[i]].profit;
        }
    }
}

int main()
{
    Job jobs[] = {
        {1, 20, 2},
        {2, 15, 2},
        {3, 10, 1},
        {4, 5, 3},
        {5, 1, 3}
    };

    int n = sizeof(jobs) / sizeof(jobs[0]); // Number of jobs

    jobSequencing(jobs, n);

    return 0;
}
