/*
 * Program 22: Implementation of Knuth-Morris-Pratt (KMP) Pattern Matching Algorithm
 * Subject: Design and Analysis of Algorithms Lab (MCA-261 / MCA-201)
 * Name: Rudransh Singh Rawat | Roll No: 06411604425
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to compute the Longest Proper Prefix which is also Suffix (LPS) array
void computeLPSArray(char *pat, int M, int *lps) {
    int len = 0; // Length of previous longest prefix suffix
    lps[0] = 0;  // lps[0] is always 0
    int i = 1;

    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Function to print the LPS array table
void printLPSTable(char *pat, int M, int *lps) {
    printf("Computed LPS (Longest Proper Prefix which is also Suffix) Table:\n");
    printf(" +-------+");
    for (int i = 0; i < M; i++) printf("----+");
    printf("\n");

    printf(" | Index |");
    for (int i = 0; i < M; i++) printf(" %2d |", i);
    printf("\n");

    printf(" +-------+");
    for (int i = 0; i < M; i++) printf("----+");
    printf("\n");

    printf(" | Char  |");
    for (int i = 0; i < M; i++) printf("  %c |", pat[i]);
    printf("\n");

    printf(" +-------+");
    for (int i = 0; i < M; i++) printf("----+");
    printf("\n");

    printf(" | LPS   |");
    for (int i = 0; i < M; i++) printf(" %2d |", lps[i]);
    printf("\n");

    printf(" +-------+");
    for (int i = 0; i < M; i++) printf("----+");
    printf("\n\n");
}

// Function to perform KMP string matching
void KMPSearch(char *pat, char *txt) {
    int M = strlen(pat);
    int N = strlen(txt);

    // Create and compute LPS array
    int *lps = (int *)malloc(sizeof(int) * M);
    computeLPSArray(pat, M, lps);

    printLPSTable(pat, M, lps);

    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    int matchCount = 0;

    printf("Search Execution:\n");
    printf("--------------------------------------------------\n");

    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            printf("  [Match Found] Pattern occurs at index %d (position %d to %d)\n",
                   i - j, i - j + 1, i);
            matchCount++;
            j = lps[j - 1]; // Use LPS value to skip redundant checks
        } else if (i < N && pat[j] != txt[i]) {
            // Mismatch after j matches
            if (j != 0) {
                j = lps[j - 1]; // Shift pattern using LPS table
            } else {
                i = i + 1;
            }
        }
    }
    printf("--------------------------------------------------\n");

    if (matchCount == 0) {
        printf("Pattern \"%s\" not found in the given text.\n", pat);
    } else {
        printf("Total occurrences found: %d\n", matchCount);
    }

    free(lps);
}

int main() {
    printf("==================================================\n");
    printf(" LAB 22: KNUTH-MORRIS-PRATT (KMP) STRING MATCHING \n");
    printf("==================================================\n\n");

    // Test Case 1: Classic matching
    char txt1[] = "ABABDABACDABABCABAB";
    char pat1[] = "ABABCABAB";

    printf(">>> Test Case 1:\n");
    printf("Text    : \"%s\" (Length = %lu)\n", txt1, strlen(txt1));
    printf("Pattern : \"%s\" (Length = %lu)\n\n", pat1, strlen(pat1));
    KMPSearch(pat1, txt1);

    printf("\n==================================================\n\n");

    // Test Case 2: Multiple occurrences (Matches Lab 10 Naive test case)
    char txt2[] = "AABAACAADAABAABA";
    char pat2[] = "AABA";

    printf(">>> Test Case 2 (Multiple Occurrences):\n");
    printf("Text    : \"%s\" (Length = %lu)\n", txt2, strlen(txt2));
    printf("Pattern : \"%s\" (Length = %lu)\n\n", pat2, strlen(pat2));
    KMPSearch(pat2, txt2);

    printf("\n==================================================\n");

    return 0;
}
