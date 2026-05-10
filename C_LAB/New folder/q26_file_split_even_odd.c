// Generate random numbers and split them into odd and even output files.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayFile(const char *fileName) {
    FILE *fp = fopen(fileName, "r");
    int num;

    if (fp == NULL) {
        printf("Cannot open %s\n", fileName);
        return;
    }

    // Stream the file contents back to the console for verification.
    printf("Contents of %s: ", fileName);
    while (fscanf(fp, "%d", &num) == 1) {
        printf("%d ", num);
    }
    printf("\n");

    fclose(fp);
}

int main() {
    int n, i, num;
    FILE *allFile, *oddFile, *evenFile;

    // Ask how many random integers should be created.
    printf("Enter how many random integers to generate: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid value of n.\n");
        return 0;
    }

    // Write all generated numbers into one source file.
    allFile = fopen("All.txt", "w");
    if (allFile == NULL) {
        printf("Cannot create All.txt\n");
        return 0;
    }

    srand((unsigned int)time(NULL));
    for (i = 0; i < n; i++) {
        num = rand() % 100;
        fprintf(allFile, "%d ", num);
    }
    fclose(allFile);

    // Reopen the source file and split each number into odd or even output.
    allFile = fopen("All.txt", "r");
    oddFile = fopen("Odd.txt", "w");
    evenFile = fopen("Even.txt", "w");

    if (allFile == NULL || oddFile == NULL || evenFile == NULL) {
        printf("Error opening files.\n");
        return 0;
    }

    while (fscanf(allFile, "%d", &num) == 1) {
        if (num % 2 == 0) {
            // Even values go into the even file.
            fprintf(evenFile, "%d ", num);
        } else {
            // Odd values go into the odd file.
            fprintf(oddFile, "%d ", num);
        }
    }

    fclose(allFile);
    fclose(oddFile);
    fclose(evenFile);

    // Print the contents of all three files so the split is visible.
    displayFile("All.txt");
    displayFile("Odd.txt");
    displayFile("Even.txt");

    return 0;
}
