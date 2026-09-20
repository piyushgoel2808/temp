/*
 * Program 16: Implementation of Longest Common Subsequence (LCS)
 * Subject: Design and Analysis of Algorithms Lab (MCA-261 / MCA-201)
 * Name: Rudransh Singh Rawat | Roll No: 06411604425
 */

#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void lcs(char *X, char *Y, int m, int n) {
    int L[m + 1][n + 1];

    // Build L[m+1][n+1] in bottom-up fashion
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    printf("Dynamic Programming Table L[i][j]:\n");
    printf("       ");
    for (int j = 0; j < n; j++) printf("  %c", Y[j]);
    printf("\n");

    for (int i = 0; i <= m; i++) {
        if (i == 0) printf("   ");
        else printf("%c: ", X[i - 1]);

        for (int j = 0; j <= n; j++) {
            printf("%3d", L[i][j]);
        }
        printf("\n");
    }

    // Following code is used to print LCS
    int index = L[m][n];
    char lcsString[index + 1];
    lcsString[index] = '\0'; // Set the terminating character

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcsString[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        } else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    printf("\nLength of Longest Common Subsequence: %d\n", L[m][n]);
    printf("Longest Common Subsequence (LCS): \"%s\"\n", lcsString);
}

int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);

    printf("========================================\n");
    printf("    LAB 16: LONGEST COMMON SUBSEQUENCE  \n");
    printf("========================================\n");
    printf("Sequence X: \"%s\" (Length: %d)\n", X, m);
    printf("Sequence Y: \"%s\" (Length: %d)\n\n", Y, n);

    lcs(X, Y, m, n);

    printf("========================================\n");

    return 0;
}
