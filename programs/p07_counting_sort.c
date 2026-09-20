/*
 * Program 07: Implementation of Counting Sort Algorithm
 * Subject: Design and Analysis of Algorithms Lab (MCA-261 / MCA-201)
 * Name: Rudransh Singh Rawat | Roll No: 06411604425
 */

#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n) {
    int max = arr[0];
    int min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    int range = max - min + 1;
    int *count = (int *)calloc(range, sizeof(int));
    int *output = (int *)malloc(sizeof(int) * n);

    // Store frequency of each element
    for (int i = 0; i < n; i++) {
        count[arr[i] - min]++;
    }

    // Accumulate count
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array (backward traversal for stability)
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    // Copy the output array to original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(count);
    free(output);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1, 9, 6, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("========================================\n");
    printf("    LAB EXPERIMENT 07: COUNTING SORT    \n");
    printf("========================================\n");
    printf("Original array:\n");
    printArray(arr, n);

    countingSort(arr, n);

    printf("\nSorted array after Counting Sort:\n");
    printArray(arr, n);
    printf("========================================\n");

    return 0;
}
