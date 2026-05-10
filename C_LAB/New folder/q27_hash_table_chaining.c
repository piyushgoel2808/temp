// Store integers in a hash table with separate chaining.
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10
#define TOTAL_VALUES 20

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *hashTable[TABLE_SIZE] = {NULL};

int hashFunction(int key) {
    // Convert negative keys to positive values before hashing.
    if (key < 0) {
        key = -key;
    }
    return key % TABLE_SIZE;
}

void insert(int key) {
    // Insert the new node at the front of the chosen bucket chain.
    int index = hashFunction(key);
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = key;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

void display() {
    int i;
    // Show each bucket and the linked list stored in that bucket.
    for (i = 0; i < TABLE_SIZE; i++) {
        Node *temp = hashTable[i];
        printf("Index %d: ", i);
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int i, value;

    // Read a fixed batch of values and place each one into the table.
    printf("Enter 20 integers (duplicates allowed):\n");
    for (i = 0; i < TOTAL_VALUES; i++) {
        scanf("%d", &value);
        insert(value);
    }

    printf("\nHash Table with Separate Chaining:\n");
    display();

    return 0;
}
