/*
 * Program 17: Matrix Chain Multiplication using Dynamic Programming
 * Subject: Design and Analysis of Algorithms Lab (MCA-261 / MCA-201)
 * Name: Rudransh Singh Rawat | Roll No: 06411604425
 */

#include <stdio.h>
#include <limits.h>

#define MAX 10

// Function to print optimal parenthesization using split table s
void printOptimalParenthesis(int s[MAX][MAX], int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        printOptimalParenthesis(s, i, s[i][j]);
        printOptimalParenthesis(s, s[i][j] + 1, j);
        printf(")");
    }
}

void matrixChainOrder(int p[], int n) {
    int m[MAX][MAX];
    int s[MAX][MAX];

    // m[i][i] is zero because single matrix needs 0 multiplication
    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    // L is chain length (from 2 to n-1)
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("Dynamic Programming Minimum Multiplications Table m[i][j]:\n");
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (i > j)
                printf("       -");
            else
                printf("%8d", m[i][j]);
        }
        printf("\n");
    }

    printf("\nSplit Table s[i][j] (Optimal cut points):\n");
    for (int i = 1; i < n - 1; i++) {
        for (int j = 2; j < n; j++) {
            if (i >= j)
                printf("   -");
            else
                printf("%4d", s[i][j]);
        }
        printf("\n");
    }

    printf("\nMinimum Scalar Multiplications Required: %d\n", m[1][n - 1]);
    printf("Optimal Parenthesization: ");
    printOptimalParenthesis(s, 1, n - 1);
    printf("\n");
}

int main() {
    // 4 matrices:
    // A1: 40x20, A2: 20x30, A3: 30x10, A4: 10x30
    int arr[] = {40, 20, 30, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("========================================\n");
    printf("   LAB 17: MATRIX CHAIN MULTIPLICATION  \n");
    printf("        (DYNAMIC PROGRAMMING)           \n");
    printf("========================================\n");
    printf("Given 4 matrices with dimensions:\n");
    for (int i = 1; i < n; i++) {
        printf("  A%d : %d x %d\n", i, arr[i - 1], arr[i]);
    }
    printf("\n");

    matrixChainOrder(arr, n);

    printf("========================================\n");

    return 0;
}
