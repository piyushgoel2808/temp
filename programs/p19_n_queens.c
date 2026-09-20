/*
 * Program 19: Implementation of N-Queens Problem using Backtracking
 * Subject: Design and Analysis of Algorithms Lab (MCA-261 / MCA-201)
 * Name: Rudransh Singh Rawat | Roll No: 06411604425
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 20

int solutionCount = 0;
int x[MAX]; // x[i] stores the column index (1-based) of the queen at row i

// Function to check if placing queen at row k and column i is safe
bool place(int k, int i) {
    for (int j = 1; j < k; j++) {
        // Check if two queens are in the same column or along the same diagonal
        if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
            return false;
        }
    }
    return true;
}

// Function to display chessboard and placement vector for a solution
void printSolution(int n) {
    solutionCount++;
    printf("--------------------------------------------------\n");
    printf(" Solution #%d:\n", solutionCount);
    printf("--------------------------------------------------\n");

    // Solution Vector Representation
    printf("  Placement Vector: X = (");
    for (int i = 1; i <= n; i++) {
        printf("%d%s", x[i], (i == n) ? "" : ", ");
    }
    printf(")\n");
    printf("  [Note: Queen in row i is located at column X[i]]\n\n");

    // Chessboard Grid Representation
    printf("  Chessboard Grid:\n");
    printf("      ");
    for (int j = 1; j <= n; j++) {
        printf(" %2d ", j);
    }
    printf("\n     +");
    for (int j = 1; j <= n; j++) {
        printf("----");
    }
    printf("+\n");

    for (int i = 1; i <= n; i++) {
        printf("  %2d |", i);
        for (int j = 1; j <= n; j++) {
            if (x[i] == j) {
                printf("  Q ");
            } else {
                printf("  . ");
            }
        }
        printf("|\n");
    }

    printf("     +");
    for (int j = 1; j <= n; j++) {
        printf("----");
    }
    printf("+\n\n");
}

// Backtracking solver for N-Queens
void nQueens(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (place(k, i)) {
            x[k] = i;
            if (k == n) {
                printSolution(n);
            } else {
                nQueens(k + 1, n);
            }
        }
    }
}

int main() {
    int n = 4;

    printf("==================================================\n");
    printf("      LAB 19: N-QUEENS PROBLEM (BACKTRACKING)     \n");
    printf("==================================================\n");
    printf("Problem Definition:\n");
    printf("  Place N non-attacking queens on an N x N chessboard.\n");
    printf("  Constraints: No two queens can share the same row,\n");
    printf("  column, or diagonal.\n");
    printf("==================================================\n\n");

    printf(">>> Solving for N = %d (%d x %d Chessboard):\n\n", n, n, n);
    solutionCount = 0;
    nQueens(1, n);

    if (solutionCount == 0) {
        printf("No solution exists for N = %d.\n", n);
    } else {
        printf("==================================================\n");
        printf(" Total distinct solutions for N = %d: %d\n", n, solutionCount);
        printf("==================================================\n");
    }

    return 0;
}
