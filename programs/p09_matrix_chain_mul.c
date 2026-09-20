/*
 * Program 09: Implementation of Matrix Chain Multiplication (MCM)
 * Subject: Design and Analysis of Algorithms Lab (MCA-261 / MCA-201)
 * Name: Rudransh Singh Rawat | Roll No: 06411604425
 */

#include <stdio.h>
#include <limits.h>

// Recursive function to calculate minimum multiplications
int matrixChainOrderRecursive(int p[], int i, int j) {
    if (i == j)
        return 0;

    int min = INT_MAX;
    int count;

    // Place parenthesis at different places between first and last matrix
    for (int k = i; k < j; k++) {
        count = matrixChainOrderRecursive(p, i, k) +
                matrixChainOrderRecursive(p, k + 1, j) +
                p[i - 1] * p[k] * p[j];

        if (count < min)
            min = count;
    }

    return min;
}

int main() {
    // Matrices dimensions:
    // A1 is 10x30, A2 is 30x5, A3 is 5x60
    int arr[] = {10, 30, 5, 60};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("========================================\n");
    printf("   LAB 09: MATRIX CHAIN MULTIPLICATION  \n");
    printf("========================================\n");
    printf("Given Matrix Dimensions:\n");
    for (int i = 1; i < n; i++) {
        printf("  Matrix A%d: %d x %d\n", i, arr[i - 1], arr[i]);
    }

    int minOps = matrixChainOrderRecursive(arr, 1, n - 1);

    printf("\nMinimum number of scalar multiplications needed: %d\n", minOps);
    printf("========================================\n");

    return 0;
}
