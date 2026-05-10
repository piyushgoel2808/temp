// Build and traverse a binary tree using level-order insertion.
#include <stdio.h>
#include <stdlib.h>

#define MAXQ 200

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *root = NULL;

Node *createNode(int value) {
    // Allocate a new tree node with empty children.
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(int value) {
    // Insert at the first available position in level order.
    Node *newNode = createNode(value);
    if (root == NULL) {
        root = newNode;
        return;
    }

    Node *queue[MAXQ];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        Node *temp = queue[front++];

        if (temp->left == NULL) {
            temp->left = newNode;
            return;
        } else {
            queue[rear++] = temp->left;
        }

        if (temp->right == NULL) {
            temp->right = newNode;
            return;
        } else {
            queue[rear++] = temp->right;
        }
    }
}

void deleteNode(int key) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }

    // Special-case a tree with just one node.
    if (root->left == NULL && root->right == NULL) {
        if (root->data == key) {
            free(root);
            root = NULL;
            printf("Node deleted.\n");
        } else {
            printf("Node not found.\n");
        }
        return;
    }

    Node *queue[MAXQ];
    int front = 0, rear = 0;
    Node *target = NULL;
    Node *temp = NULL;
    Node *parentOfDeepest = NULL;

    queue[rear++] = root;

    // Find both the node to delete and the deepest node in the tree.
    while (front < rear) {
        temp = queue[front++];

        if (temp->data == key) {
            target = temp;
        }

        if (temp->left != NULL) {
            parentOfDeepest = temp;
            queue[rear++] = temp->left;
        }

        if (temp->right != NULL) {
            parentOfDeepest = temp;
            queue[rear++] = temp->right;
        }
    }

    if (target == NULL) {
        printf("Node not found.\n");
        return;
    }

    // Replace the target value with the deepest node's value.
    target->data = temp->data;

    // Remove the deepest node from its parent.
    if (parentOfDeepest->right == temp) {
        parentOfDeepest->right = NULL;
    } else {
        parentOfDeepest->left = NULL;
    }
    free(temp);

    printf("Node deleted.\n");
}

void preorder(Node *node) {
    if (node != NULL) {
        // Visit the current node before its children.
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

void inorder(Node *node) {
    if (node != NULL) {
        // Visit left subtree, then node, then right subtree.
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

void postorder(Node *node) {
    if (node != NULL) {
        // Visit children before printing the current node.
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->data);
    }
}

int countLeaves(Node *node) {
    if (node == NULL) {
        return 0;
    }
    // A leaf has no left or right child.
    if (node->left == NULL && node->right == NULL) {
        return 1;
    }
    return countLeaves(node->left) + countLeaves(node->right);
}

int main() {
    int choice, value;

    // Keep offering tree operations until the user exits.
    do {
        printf("\n1. Insert node\n2. Delete node\n3. Preorder\n4. Inorder\n5. Postorder\n6. Count leaf nodes\n7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertNode(value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;
            case 3:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;
            case 6:
                printf("Leaf nodes = %d\n", countLeaves(root));
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 7);

    return 0;
}
