/*
 * Program 10: Implementation of Naive String Matching Algorithm
 * Subject: Design and Analysis of Algorithms Lab (MCA-261 / MCA-201)
 * Name: Rudransh Singh Rawat | Roll No: 06411604425
 */

#include <stdio.h>
#include <string.h>

void naiveStringSearch(char* pat, char* txt) {
    int M = strlen(pat);
    int N = strlen(txt);
    int matchFound = 0;

    printf("Searching for pattern \"%s\" in text:\n\"%s\"\n\n", pat, txt);

    // Slide pattern over text one by one
    for (int i = 0; i <= N - M; i++) {
        int j;

        // For current index i, check for pattern match
        for (j = 0; j < M; j++) {
            if (txt[i + j] != pat[j])
                break;
        }

        if (j == M) { // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
            printf("  [Match Found] Pattern occurs at shift/index: %d\n", i);
            matchFound++;
        }
    }

    if (!matchFound) {
        printf("Pattern not found in the given text.\n");
    } else {
        printf("\nTotal occurrences found: %d\n", matchFound);
    }
}

int main() {
    char txt[] = "AABAACAADAABAABA";
    char pat[] = "AABA";

    printf("========================================\n");
    printf(" LAB 10: NAIVE STRING MATCHING ALGORITHM\n");
    printf("========================================\n");

    naiveStringSearch(pat, txt);

    printf("========================================\n");

    return 0;
}
