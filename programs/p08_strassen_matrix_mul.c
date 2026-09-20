/*
 * Program 08: Implementation of Strassen's Matrix Multiplication
 * Subject: Design and Analysis of Algorithms Lab (MCA-261 / MCA-201)
 * Name: Rudransh Singh Rawat | Roll No: 06411604425
 */

#include <stdio.h>

void strassenMultiply2x2(int A[2][2], int B[2][2], int C[2][2]) {
    // Calculating the 7 Strassen formulas
    int m1 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
    int m2 = (A[1][0] + A[1][1]) * B[0][0];
    int m3 = A[0][0] * (B[0][1] - B[1][1]);
    int m4 = A[1][1] * (B[1][0] - B[0][0]);
    int m5 = (A[0][0] + A[0][1]) * B[1][1];
    int m6 = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
    int m7 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);

    printf("Computed Strassen 7 Sub-multiplications:\n");
    printf("  M1 = %d\n", m1);
    printf("  M2 = %d\n", m2);
    printf("  M3 = %d\n", m3);
    printf("  M4 = %d\n", m4);
    printf("  M5 = %d\n", m5);
    printf("  M6 = %d\n", m6);
    printf("  M7 = %d\n\n", m7);

    // Combining results into C matrix
    C[0][0] = m1 + m4 - m5 + m7;
    C[0][1] = m3 + m5;
    C[1][0] = m2 + m4;
    C[1][1] = m1 - m2 + m3 + m6;
}

void printMatrix(int M[2][2]) {
    for (int i = 0; i < 2; i++) {
        printf("  [ ");
        for (int j = 0; j < 2; j++) {
            printf("%3d ", M[i][j]);
        }
        printf("]\n");
    }
}

int main() {
    int A[2][2] = {
        {1, 3},
        {7, 5}
    };

    int B[2][2] = {
        {6, 8},
        {4, 2}
    };

    int C[2][2];

    printf("========================================\n");
    printf(" LAB 08: STRASSEN MATRIX MULTIPLICATION \n");
    printf("========================================\n");
    printf("Matrix A (2x2):\n");
    printMatrix(A);

    printf("\nMatrix B (2x2):\n");
    printMatrix(B);
    printf("\n");

    strassenMultiply2x2(A, B, C);

    printf("Resultant Matrix C (A x B):\n");
    printMatrix(C);
    printf("========================================\n");

    return 0;
}
