/*
 * A3 / P21. Write a program to find solution for job sequencing with deadlines problem.
 * Compatible with Turbo C++ 3.0
 * Subject: Design and Analysis of Algorithms Lab (MCA-201)
 * Name: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem, Sec-B
 */

#include <iostream.h>
#include <conio.h>

#define MAX_JOBS 20
#define MIN_VAL(a, b) ((a) < (b) ? (a) : (b))

struct Job
{
    int id;
    int profit;
    int deadline;
};

void swapJobs(Job *a, Job *b)
{
    Job temp = *a;
    *a = *b;
    *b = temp;
}

void sortJobs(Job jobs[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (jobs[j].profit < jobs[j + 1].profit)
            {
                swapJobs(&jobs[j], &jobs[j + 1]);
            }
        }
    }
}

void jobSequencing(Job jobs[], int n)
{
    int result[MAX_JOBS];
    int slot[MAX_JOBS];
    int i, j, limit, totalProfit;

    sortJobs(jobs, n);

    for (i = 0; i < n; i++)
        slot[i] = 0;

    for (i = 0; i < n; i++)
    {
        limit = MIN_VAL(n, jobs[i].deadline);
        for (j = limit - 1; j >= 0; j--)
        {
            if (!slot[j])
            {
                slot[j] = 1;
                result[j] = i;
                break;
            }
        }
    }

    cout << "Scheduled Jobs:\n";
    totalProfit = 0;
    for (i = 0; i < n; i++)
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
    Job jobs[5];
    int n = 5;

    clrscr();

    jobs[0].id = 1; jobs[0].profit = 20; jobs[0].deadline = 2;
    jobs[1].id = 2; jobs[1].profit = 15; jobs[1].deadline = 2;
    jobs[2].id = 3; jobs[2].profit = 10; jobs[2].deadline = 1;
    jobs[3].id = 4; jobs[3].profit = 5;  jobs[3].deadline = 3;
    jobs[4].id = 5; jobs[4].profit = 1;  jobs[4].deadline = 3;

    jobSequencing(jobs, n);

    getch();
    return 0;
}
