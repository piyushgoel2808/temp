/*
 * Program 21: Implementation of Job Sequencing with Deadlines (Greedy Approach)
 * Subject: Design and Analysis of Algorithms Lab (MCA-261 / MCA-201)
 * Name: Rudransh Singh Rawat | Roll No: 06411604425
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_JOBS 50

typedef struct {
    char id[10];
    int deadline;
    int profit;
} Job;

// Comparator to sort jobs in descending order of profit
int compareJobs(const void *a, const void *b) {
    Job *j1 = (Job *)a;
    Job *j2 = (Job *)b;
    return (j2->profit - j1->profit);
}

// Function to find maximum deadline among all jobs
int findMaxDeadline(Job jobs[], int n) {
    int maxD = jobs[0].deadline;
    for (int i = 1; i < n; i++) {
        if (jobs[i].deadline > maxD) {
            maxD = jobs[i].deadline;
        }
    }
    return maxD;
}

void jobSequencing(Job jobs[], int n) {
    printf("Original Job List:\n");
    printf(" +---------+----------+--------+\n");
    printf(" | Job ID  | Deadline | Profit |\n");
    printf(" +---------+----------+--------+\n");
    for (int i = 0; i < n; i++) {
        printf(" | %-7s | %8d | %6d |\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
    }
    printf(" +---------+----------+--------+\n\n");

    // Step 1: Sort jobs by profit in descending order
    qsort(jobs, n, sizeof(Job), compareJobs);

    printf("Jobs Sorted by Profit (Descending Order):\n");
    printf(" +---------+----------+--------+\n");
    printf(" | Job ID  | Deadline | Profit |\n");
    printf(" +---------+----------+--------+\n");
    for (int i = 0; i < n; i++) {
        printf(" | %-7s | %8d | %6d |\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
    }
    printf(" +---------+----------+--------+\n\n");

    int maxDeadline = findMaxDeadline(jobs, n);

    // Slot array represents time slots from 1 to maxDeadline
    // slot[t] stores index of job scheduled in slot [t-1, t]
    int *slot = (int *)malloc((maxDeadline + 1) * sizeof(int));
    for (int i = 0; i <= maxDeadline; i++) {
        slot[i] = -1; // -1 denotes slot is empty
    }

    int totalProfit = 0;
    int countJobs = 0;

    printf("Slot Allocation Process:\n");
    printf("--------------------------------------------------\n");

    // Step 2: Greedily allocate slots for sorted jobs
    for (int i = 0; i < n; i++) {
        // Search for a free slot from min(maxDeadline, deadline) down to 1
        int searchLimit = (jobs[i].deadline < maxDeadline) ? jobs[i].deadline : maxDeadline;
        bool scheduled = false;

        for (int j = searchLimit; j >= 1; j--) {
            if (slot[j] == -1) {
                slot[j] = i; // Assign job to slot j
                totalProfit += jobs[i].profit;
                countJobs++;
                scheduled = true;
                printf("  -> Job %-4s (Profit: %3d, Deadline: %d) allocated to Time Slot [%d - %d]\n",
                       jobs[i].id, jobs[i].profit, jobs[i].deadline, j - 1, j);
                break;
            }
        }

        if (!scheduled) {
            printf("  -> Job %-4s (Profit: %3d, Deadline: %d) REJECTED (no available slot before deadline)\n",
                   jobs[i].id, jobs[i].profit, jobs[i].deadline);
        }
    }
    printf("--------------------------------------------------\n\n");

    // Final Job Schedule Output
    printf("Final Execution Schedule:\n");
    printf(" +-----------+---------+--------+\n");
    printf(" | Time Slot | Job ID  | Profit |\n");
    printf(" +-----------+---------+--------+\n");
    for (int j = 1; j <= maxDeadline; j++) {
        if (slot[j] != -1) {
            int idx = slot[j];
            printf(" |  [%d - %d]   | %-7s | %6d |\n", j - 1, j, jobs[idx].id, jobs[idx].profit);
        } else {
            printf(" |  [%d - %d]   | %-7s | %6s |\n", j - 1, j, "IDLE", "-");
        }
    }
    printf(" +-----------+---------+--------+\n\n");

    printf("Optimal Job Sequence: < ");
    bool first = true;
    for (int j = 1; j <= maxDeadline; j++) {
        if (slot[j] != -1) {
            if (!first) printf(", ");
            printf("%s", jobs[slot[j]].id);
            first = false;
        }
    }
    printf(" >\n");
    printf("Total Number of Jobs Scheduled : %d\n", countJobs);
    printf("Maximum Total Profit Earned    : %d\n", totalProfit);

    free(slot);
}

int main() {
    Job jobs[] = {
        {"J1", 2, 100},
        {"J2", 1, 19},
        {"J3", 2, 27},
        {"J4", 1, 25},
        {"J5", 3, 15}
    };
    int n = sizeof(jobs) / sizeof(jobs[0]);

    printf("==================================================\n");
    printf("  LAB 21: JOB SEQUENCING WITH DEADLINES (GREEDY)  \n");
    printf("==================================================\n\n");

    jobSequencing(jobs, n);

    printf("==================================================\n");

    return 0;
}
