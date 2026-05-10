// Detect whether a matrix is sparse and print its compact form.
#include <stdio.h>

int main() {
    int m, n, i, j;
    int matrix[20][20];

    // Read the matrix dimensions first.
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    if (m <= 0 || n <= 0 || m > 20 || n > 20) {
        printf("Invalid size.\n");
        return 0;
    }

    // Store every matrix entry from the user.
    printf("Enter matrix elements:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Count zeros to determine whether the matrix qualifies as sparse.
    int zeroCount = 0;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                zeroCount++;
            }
        }
    }

    if (zeroCount > (m * n) / 2) {
        // Print only the non-zero values when the matrix is sparse.
        printf("The matrix is a sparse matrix.\n");
        printf("Sparse representation (row column value):\n");

        int nonZero = m * n - zeroCount;
        printf("%d %d %d\n", m, n, nonZero);
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (matrix[i][j] != 0) {
                    printf("%d %d %d\n", i, j, matrix[i][j]);
                }
            }
        }
    } else {
        // Otherwise, report that the matrix does not meet the sparse rule.
        printf("The matrix is not a sparse matrix.\n");
    }

    return 0;
}
