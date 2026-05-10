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

    printf("Enter how many random integers to generate: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid value of n.\n");
        return 0;
    }

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

    allFile = fopen("All.txt", "r");
    oddFile = fopen("Odd.txt", "w");
    evenFile = fopen("Even.txt", "w");

    if (allFile == NULL || oddFile == NULL || evenFile == NULL) {
        printf("Error opening files.\n");
        return 0;
    }

    while (fscanf(allFile, "%d", &num) == 1) {
        if (num % 2 == 0) {
            fprintf(evenFile, "%d ", num);
        } else {
            fprintf(oddFile, "%d ", num);
        }
    }

    fclose(allFile);
    fclose(oddFile);
    fclose(evenFile);

    displayFile("All.txt");
    displayFile("Odd.txt");
    displayFile("Even.txt");

    return 0;
}
