#include <stdio.h>

void bubbleSortDescending(int a[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
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
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int n, i;
    int arr[100], bArr[100], sArr[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Invalid size.\n");
        return 0;
    }

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        bArr[i] = arr[i];
        sArr[i] = arr[i];
    }

    bubbleSortDescending(bArr, n);
    selectionSortDescending(sArr, n);

    printf("Bubble Sort (Descending): ");
    printArray(bArr, n);

    printf("Selection Sort (Descending): ");
    printArray(sArr, n);

    return 0;
}
