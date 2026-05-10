// Use selection sort to repeatedly place the smallest value in front.
#include <stdio.h>

void selectionSortAscending(int a[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        // Assume the current position has the minimum element.
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
    }
}

int main() {
    int n, i;
    int arr[100];

    // Read and validate the number of values to sort.
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Invalid size.\n");
        return 0;
    }

    // Collect the numbers from the user.
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array in ascending order.
    selectionSortAscending(arr, n);

    // Print the sorted sequence.
    printf("Sorted array (Ascending): ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
