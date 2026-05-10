
#include <stdio.h>

int main() {
    int n, i, j;
    int arr[100], visited[100] = {0};

    // Ask the user how many numbers will be processed.
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Guard against invalid input and array overflow.
    if (n <= 0 || n > 100) {
        printf("Invalid size.\n");
        return 0;
    }

    // Read the input values into the array.
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Count and print each unique value only once.
    printf("\nFrequency of each element:\n");
    for (i = 0; i < n; i++) {
        // Skip values that were already counted earlier.
        if (visited[i]) {
            continue;
        }

        // Start by assuming the current value appears once.
        int count = 1;
        for (j = i + 1; j < n; j++) {
            // Mark duplicates so they are not counted again later.
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = 1;
            }
        }

        // Report the final frequency for this distinct value.
        printf("%d occurs %d time(s)\n", arr[i], count);
    }

    return 0;
}
