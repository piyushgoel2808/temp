// Compare two descending sorts on the same input array.
#include <stdio.h>

void bubbleSortDescending(int a[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        // Move smaller values toward the end on each pass.
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] < a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void selectionSortDescending(int a[], int n) {
    int i, j, maxIndex, temp;
    for (i = 0; i < n - 1; i++) {
        // Find the largest remaining value and place it at the front.
        maxIndex = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] > a[maxIndex]) {
                maxIndex = j;
            }
        }
        temp = a[i];
        a[i] = a[maxIndex];
        a[maxIndex] = temp;
    }
}

void printArray(int a[], int n) {
    int i;
    // Print the array in a single line for easy comparison.
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int n, i;
    int arr[100], bArr[100], sArr[100];

    // Get the number of elements and make sure the fixed array can hold them.
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Invalid size.\n");
        return 0;
    }

    // Copy the same input into two arrays so each sort can run independently.
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        bArr[i] = arr[i];
        sArr[i] = arr[i];
    }

    bubbleSortDescending(bArr, n);
    selectionSortDescending(sArr, n);

    // Print both sorted results so the user can compare the algorithms.
    printf("Bubble Sort (Descending): ");
    printArray(bArr, n);

    printf("Selection Sort (Descending): ");
    printArray(sArr, n);

    return 0;
}
