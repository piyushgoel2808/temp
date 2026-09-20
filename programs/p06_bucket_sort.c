/*
 * Program 06: Implementation of Bucket Sort Algorithm
 * Subject: Design and Analysis of Algorithms Lab (MCA-261 / MCA-201)
 * Name: Rudransh Singh Rawat | Roll No: 06411604425
 */

#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list bucket
struct Node {
    float data;
    struct Node *next;
};

// Function to sort individual buckets using Insertion Sort
struct Node *insertionSort(struct Node *list) {
    if (list == NULL || list->next == NULL)
        return list;

    struct Node *sorted = NULL;
    struct Node *current = list;

    while (current != NULL) {
        struct Node *next = current->next;

        if (sorted == NULL || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            struct Node *temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    return sorted;
}

// Function to perform bucket sort
void bucketSort(float arr[], int n) {
    // 1) Create n empty buckets
    struct Node **buckets = (struct Node **)malloc(sizeof(struct Node *) * n);
    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }

    // 2) Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        struct Node *current = (struct Node *)malloc(sizeof(struct Node));
        current->data = arr[i];
        current->next = NULL;

        int bucketIndex = (int)(n * arr[i]);
        if (bucketIndex >= n)
            bucketIndex = n - 1;

        // Insert at beginning of linked list for bucket
        current->next = buckets[bucketIndex];
        buckets[bucketIndex] = current;
    }

    // 3) Sort each bucket using insertion sort
    for (int i = 0; i < n; i++) {
        buckets[i] = insertionSort(buckets[i]);
    }

    // 4) Concatenate all buckets into arr[]
    int idx = 0;
    for (int i = 0; i < n; i++) {
        struct Node *node = buckets[i];
        while (node != NULL) {
            arr[idx++] = node->data;
            struct Node *temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(buckets);
}

void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.3f ", arr[i]);
    }
    printf("\n");
}

int main() {
    float arr[] = {0.897f, 0.565f, 0.656f, 0.1234f, 0.665f, 0.3434f, 0.456f};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("========================================\n");
    printf("     LAB EXPERIMENT 06: BUCKET SORT     \n");
    printf("========================================\n");
    printf("Original array of floating numbers:\n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("\nSorted array after Bucket Sort:\n");
    printArray(arr, n);
    printf("========================================\n");

    return 0;
}
