// Implement a max heap that keeps the largest value at the root.
#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

void insert(int value) {
    // Place the new value at the end and bubble it up.
    if (size == MAX) {
        printf("Heap Overflow\n");
        return;
    }

    int i = size;
    heap[size++] = value;

    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] < heap[i]) {
            int temp = heap[parent];
            heap[parent] = heap[i];
            heap[i] = temp;
            i = parent;
        } else {
            break;
        }
    }
}

void deleteRoot() {
    // Remove the root, move the last element to the top, then heapify down.
    if (size == 0) {
        printf("Heap is empty\n");
        return;
    }

    printf("Deleted node: %d\n", heap[0]);
    heap[0] = heap[size - 1];
    size--;

    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < size && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < size && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest != i) {
            int temp = heap[i];
            heap[i] = heap[largest];
            heap[largest] = temp;
            i = largest;
        } else {
            break;
        }
    }
}

void display() {
    int i;
    if (size == 0) {
        printf("Heap is empty\n");
        return;
    }

    // Print the heap in array order, which matches its internal structure.
    printf("Heap elements: ");
    for (i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    // Use a menu to exercise the heap operations.
    do {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                deleteRoot();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}
