// Store two independent stacks in one shared array.
#include <stdio.h>

#define MAX 100

int arr[MAX];
int top1 = -1;
int top2 = MAX;

void push1(int value) {
    // Stack 1 grows from the left side of the array.
    if (top1 + 1 == top2) {
        printf("No space left for Stack 1\n");
        return;
    }
    arr[++top1] = value;
    printf("Pushed %d in Stack 1\n", value);
}

void push2(int value) {
    // Stack 2 grows from the right side of the array.
    if (top1 + 1 == top2) {
        printf("No space left for Stack 2\n");
        return;
    }
    arr[--top2] = value;
    printf("Pushed %d in Stack 2\n", value);
}

void pop1() {
    // Pop the most recent value from the left-hand stack.
    if (top1 == -1) {
        printf("Stack 1 Underflow\n");
        return;
    }
    printf("Popped %d from Stack 1\n", arr[top1--]);
}

void pop2() {
    // Pop the most recent value from the right-hand stack.
    if (top2 == MAX) {
        printf("Stack 2 Underflow\n");
        return;
    }
    printf("Popped %d from Stack 2\n", arr[top2++]);
}

void display() {
    int i;

    // Print both stacks so their shared layout is easy to see.
    printf("Stack 1: ");
    if (top1 == -1) {
        printf("Empty");
    } else {
        for (i = top1; i >= 0; i--) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");

    printf("Stack 2: ");
    if (top2 == MAX) {
        printf("Empty");
    } else {
        for (i = top2; i < MAX; i++) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int main() {
    int choice, value;

    // Use the menu to operate on either stack.
    do {
        printf("\n1. Push Stack1\n2. Pop Stack1\n3. Push Stack2\n4. Pop Stack2\n5. Display\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push1(value);
                break;
            case 2:
                pop1();
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                push2(value);
                break;
            case 4:
                pop2();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 6);

    return 0;
}
