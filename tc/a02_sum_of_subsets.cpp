/*
 * A2 / P20. Write a program to solve Sum of subsets problem for a given set of distinct numbers.
 * Compatible with Turbo C++ 3.0
 * Subject: Design and Analysis of Algorithms Lab (MCA-201)
 * Name: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem, Sec-B
 */

#include <iostream.h>
#include <conio.h>

void printSubset(int subset[], int size)
{
    int i;
    cout << "{ ";
    for (i = 0; i < size; i++)
    {
        cout << subset[i] << " ";
    }
    cout << "}\n";
}

void findSubsetSum(int arr[], int n, int target, int subset[], int subsetSize, int index, int &found)
{
    if (target == 0)
    {
        printSubset(subset, subsetSize);
        found = 1;
        return;
    }

    if (index >= n || target < 0)
    {
        return;
    }

    subset[subsetSize] = arr[index];
    findSubsetSum(arr, n, target - arr[index], subset, subsetSize + 1, index + 1, found);
    findSubsetSum(arr, n, target, subset, subsetSize, index + 1, found);
}

void sumOfSubsets(int arr[], int n, int target)
{
    int subset[50];
    int found = 0;

    cout << "Subsets that sum to " << target << ":\n";
    findSubsetSum(arr, n, target, subset, 0, 0, found);

    if (!found)
    {
        cout << "No subset found that sums to " << target << ".\n";
    }
}

int main()
{
    int arr[] = {3, 34, 4, 12, 5, 2};
    int target = 9;
    int n = sizeof(arr) / sizeof(arr[0]);

    clrscr();

    sumOfSubsets(arr, n, target);

    getch();
    return 0;
}
