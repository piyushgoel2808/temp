#include <stdio.h>

#define MAX 100

int pq[MAX];
int size = 0;

void enqueue(int value) {
    if (size == MAX) {
        printf("Priority Queue Overflow\n");
        return;
    }
    pq[size++] = value;
    printf("Inserted %d\n", value);
}

void dequeue() {
    if (size == 0) {
        printf("Priority Queue Underflow\n");
        return;
    }

    int minIndex = 0;
    int i;
    for (i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }

    printf("Deleted highest priority element (smallest): %d\n", pq[minIndex]);

    for (i = minIndex; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;
}

void display() {
    int i;
    if (size == 0) {
        printf("Priority Queue is empty\n");
        return;
    }

    printf("Elements: ");
    for (i = 0; i < size; i++) {
        printf("%d ", pq[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
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
