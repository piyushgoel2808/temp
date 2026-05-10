// Demonstrate insertion sort, which builds a sorted prefix one item at a time.
#include <stdio.h>

void insertionSort(int a[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        // Save the current value and shift larger elements rightward.
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main() {
    int n, i;
    int arr[100];

    // Read the number of elements and keep it inside the array limit.
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Invalid size.\n");
        return 0;
    }

    // Load the unsorted values from the user.
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the data in place.
    insertionSort(arr, n);

    // Display the final ordered array.
    printf("Sorted array (Ascending): ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
