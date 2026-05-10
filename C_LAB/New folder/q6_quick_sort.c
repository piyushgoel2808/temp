// Implement quick sort using the last element as the pivot.
#include <stdio.h>

void quickSort(int a[], int low, int high) {
    if (low < high) {
        // Partition the array around the pivot value.
        int pivot = a[high];
        int i = low - 1;
        int j, temp;

        for (j = low; j < high; j++) {
            if (a[j] <= pivot) {
                i++;
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

        temp = a[i + 1];
        a[i + 1] = a[high];
        a[high] = temp;

        int pIndex = i + 1;
        quickSort(a, low, pIndex - 1);
        quickSort(a, pIndex + 1, high);
    }
}

int main() {
    int n, i;
    int arr[100];

    // Read the array length and keep it within bounds.
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Invalid size.\n");
        return 0;
    }

    // Input the numbers that will be sorted.
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array recursively.
    quickSort(arr, 0, n - 1);

    // Show the final ascending order.
    printf("Sorted array (Ascending): ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
