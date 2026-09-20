/*
 * Program 20: Implementation of Sum of Subsets Problem using Backtracking
 * Subject: Design and Analysis of Algorithms Lab (MCA-261 / MCA-201)
 * Name: Rudransh Singh Rawat | Roll No: 06411604425
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 50

int w[MAX];          // Array of distinct weights/numbers (1-indexed)
int x[MAX];          // Selection vector: x[i] = 1 if w[i] included, else 0
int n;               // Total number of elements
int M;               // Target sum
int solutionCount = 0;

// Comparison function for sorting elements in ascending order
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to print a valid subset solution
void printSolution(int k) {
    solutionCount++;
    printf("--------------------------------------------------\n");
    printf(" Solution #%d:\n", solutionCount);
    printf("--------------------------------------------------\n");

    // Print full binary selection vector (x1, x2, ..., xn)
    printf("  Selection Vector: X = (");
    for (int i = 1; i <= n; i++) {
        printf("%d%s", (i <= k) ? x[i] : 0, (i == n) ? "" : ", ");
    }
    printf(")\n");

    // Print the elements belonging to the subset
    printf("  Subset Elements : { ");
    int first = 1;
    for (int i = 1; i <= k; i++) {
        if (x[i] == 1) {
            if (!first) printf(", ");
            printf("%d", w[i]);
            first = 0;
        }
    }
    printf(" }\n");

    // Print arithmetic verification
    printf("  Verification    : ");
    first = 1;
    for (int i = 1; i <= k; i++) {
        if (x[i] == 1) {
            if (!first) printf(" + ");
            printf("%d", w[i]);
            first = 0;
        }
    }
    printf(" = %d\n\n", M);
}

// Recursive Backtracking function for Sum of Subsets
// s = current sum, k = current index, r = remaining sum of elements
void sumOfSubsets(int s, int k, int r) {
    if (k > n) return;

    // Case 1: Include element w[k] (Left child in State Space Tree)
    x[k] = 1;
    if (s + w[k] == M) {
        // Target sum achieved
        printSolution(k);
    } else if (k + 1 <= n && s + w[k] + w[k + 1] <= M) {
        // Pruning condition: proceed only if sum doesn't exceed M with next element
        sumOfSubsets(s + w[k], k + 1, r - w[k]);
    }

    // Case 2: Exclude element w[k] (Right child in State Space Tree)
    // Pruning condition: proceed only if remaining elements can reach M and next element fits
    if (k + 1 <= n && (s + r - w[k] >= M) && (s + w[k + 1] <= M)) {
        x[k] = 0;
        sumOfSubsets(s, k + 1, r - w[k]);
    }
}

int main() {
    // Demonstration set of distinct numbers
    int rawSet[] = {15, 10, 12, 13, 5, 18};
    int totalElements = sizeof(rawSet) / sizeof(rawSet[0]);
    M = 30; // Desired target sum

    printf("==================================================\n");
    printf("    LAB 20: SUM OF SUBSETS PROBLEM (BACKTRACKING) \n");
    printf("==================================================\n");

    printf("Given Set of Distinct Numbers:\n  { ");
    for (int i = 0; i < totalElements; i++) {
        printf("%d%s", rawSet[i], (i == totalElements - 1) ? "" : ", ");
    }
    printf(" }\n");
    printf("Target Sum (M) = %d\n\n", M);

    // Sort the numbers in non-decreasing order (standard requirement)
    qsort(rawSet, totalElements, sizeof(int), compare);

    n = totalElements;
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        w[i + 1] = rawSet[i]; // Store in 1-based indexed array
        totalSum += w[i + 1];
        x[i + 1] = 0;
    }

    printf("Sorted Set Elements:\n  { ");
    for (int i = 1; i <= n; i++) {
        printf("%d%s", w[i], (i == n) ? "" : ", ");
    }
    printf(" }\n");
    printf("Total Sum of all Elements = %d\n", totalSum);
    printf("==================================================\n\n");

    // Quick boundary checks
    if (totalSum < M || w[1] > M) {
        printf("No subset is possible (Target M is either > Total Sum or < Minimum Element).\n");
        return 0;
    }

    solutionCount = 0;
    printf("Searching for all subsets summing to %d...\n\n", M);
    sumOfSubsets(0, 1, totalSum);

    printf("==================================================\n");
    if (solutionCount == 0) {
        printf("No subset sums up to %d.\n", M);
    } else {
        printf("Total valid subset solutions found: %d\n", solutionCount);
    }
    printf("==================================================\n");

    return 0;
}
