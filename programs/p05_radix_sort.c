/*
 * Program 05: Implementation of Radix Sort Algorithm
 * Subject: Design and Analysis of Algorithms Lab (MCA-261 / MCA-201)
 * Name: Rudransh Singh Rawat | Roll No: 06411604425
 */

#include <stdio.h>

// Utility function to get the maximum value in arr[]
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Counting sort subroutine based on the digit represented by exp (10^i)
void countSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Change count[i] so that count[i] contains actual position in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array (traverse backwards for stable sort)
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] contains sorted numbers
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// The main Radix Sort function
void radixSort(int arr[], int n) {
    int m = getMax(arr, n);

    // Do counting sort for every digit. exp is 10^i where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("========================================\n");
    printf("      LAB EXPERIMENT 05: RADIX SORT     \n");
    printf("========================================\n");
    printf("Original array of numbers:\n");
    printArray(arr, n);

    radixSort(arr, n);

    printf("\nSorted array after Radix Sort:\n");
    printArray(arr, n);
    printf("========================================\n");

    return 0;
}
