/*
 * Program 04: Implementation of Binary Search Algorithm
 * Subject: Design and Analysis of Algorithms Lab (MCA-261 / MCA-201)
 * Name: Rudransh Singh Rawat | Roll No: 06411604425
 */

#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;

        // Check if x is present at mid
        if (arr[m] == x)
            return m;

        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;
        // If x is smaller, ignore right half
        else
            r = m - 1;
    }

    // Element was not present
    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key1 = 23;
    int key2 = 50;

    printf("========================================\n");
    printf("    LAB EXPERIMENT 04: BINARY SEARCH    \n");
    printf("========================================\n");
    printf("Given sorted array elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    // Case 1: Search existing element
    int result1 = binarySearch(arr, 0, n - 1, key1);
    if (result1 != -1)
        printf("Searching for %d -> Element found at index %d (position %d).\n", key1, result1, result1 + 1);
    else
        printf("Searching for %d -> Element not present in array.\n", key1);

    // Case 2: Search non-existing element
    int result2 = binarySearch(arr, 0, n - 1, key2);
    if (result2 != -1)
        printf("Searching for %d -> Element found at index %d (position %d).\n", key2, result2, result2 + 1);
    else
        printf("Searching for %d -> Element not present in array.\n", key2);

    printf("========================================\n");

    return 0;
}
