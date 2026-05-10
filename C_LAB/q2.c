#include <stdio.h>

void sortAscending(int a[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int linearSearch(int a[], int n, int key) {
    int i;
    for (i = 0; i < n; i++) {
        if (a[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int a[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] == key) {
            return mid;
        }
        if (a[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n, i, key;
    int arr[100], sorted[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Invalid size.\n");
        return 0;
    }

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sorted[i] = arr[i];
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    int lIndex = linearSearch(arr, n, key);
    if (lIndex != -1) {
        printf("Linear Search: Found at index %d\n", lIndex);
    } else {
        printf("Linear Search: Not found\n");
    }

    sortAscending(sorted, n);
    int bIndex = binarySearch(sorted, n, key);
    if (bIndex != -1) {
        printf("Binary Search: Found at sorted index %d\n", bIndex);
    } else {
        printf("Binary Search: Not found\n");
    }

    return 0;
}
