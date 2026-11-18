/*
 * A2. Write a program to solve Sum of subsets problem for a given set of distinct numbers.
 * Subject: Design and Analysis of Algorithms Lab (MCA-201)
 * Name: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem, Sec-B
 */

#include <iostream>
using namespace std;

// Function to print the subset
void printSubset(int subset[], int size)
{
    cout << "{ ";
    for (int i = 0; i < size; i++)
    {
        cout << subset[i] << " ";
    }
    cout << "}\n";
}

// Recursive function to find subsets that sum to a given value
void findSubsetSum(int arr[], int n, int target, int subset[], int subsetSize, int index, bool &found)
{
    // Base case: If we reach the target
    if (target == 0)
    {
        printSubset(subset, subsetSize);
        found = true;
        return;
    }

    // If we reach the end of the array or target becomes negative
    if (index >= n || target < 0)
    {
        return;
    }

    // Include the current element in the subset
    subset[subsetSize] = arr[index];
    findSubsetSum(arr, n, target - arr[index], subset, subsetSize + 1, index + 1, found);

    // Exclude the current element from the subset and move to next
    findSubsetSum(arr, n, target, subset, subsetSize, index + 1, found);
}

// Function to solve the Sum of Subsets problem
void sumOfSubsets(int arr[], int n, int target)
{
    int subset[100];
    bool found = false;
    cout << "Subsets that sum to " << target << ":\n";
    findSubsetSum(arr, n, target, subset, 0, 0, found);

    // If no subset was found
    if (!found)
    {
        cout << "No subset found that sums to " << target << ".\n";
    }
}

int main()
{
    int arr[] = {3, 34, 4, 12, 5, 2}; // Example set
    int target = 9;                    // Example target sum
    int n = sizeof(arr) / sizeof(arr[0]);

    sumOfSubsets(arr, n, target);

    return 0;
}
