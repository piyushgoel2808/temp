#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode {
    int coeff;
    int exp;
    struct PolyNode *next;
} PolyNode;

PolyNode *createNode(int c, int e) {
    PolyNode *node = (PolyNode *)malloc(sizeof(PolyNode));
    node->coeff = c;
    node->exp = e;
    node->next = NULL;
    return node;
}

void appendTerm(PolyNode **head, int c, int e) {
    PolyNode *newNode = createNode(c, e);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    PolyNode *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayPoly(PolyNode *head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }

    while (head != NULL) {
        if (head->coeff > 0 && head != NULL) {
            printf("%d", head->coeff);
        } else {
            printf("(%d)", head->coeff);
        }

        if (head->exp > 1) {
            printf("x^%d", head->exp);
        } else if (head->exp == 1) {
            printf("x");
        }

        if (head->next != NULL) {
            printf(" + ");
        }
        head = head->next;
    }
    printf("\n");
}

PolyNode *addPoly(PolyNode *p1, PolyNode *p2) {
    PolyNode *result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp == p2->exp) {
            appendTerm(&result, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->exp > p2->exp) {
            appendTerm(&result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else {
            appendTerm(&result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        appendTerm(&result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        appendTerm(&result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

int main() {
    PolyNode *p1 = NULL, *p2 = NULL, *sum;

    appendTerm(&p1, 4, 4);
    appendTerm(&p1, 4, 3);
    appendTerm(&p1, -2, 2);
    appendTerm(&p1, 1, 1);

    appendTerm(&p2, 11, 3);
    appendTerm(&p2, 7, 2);
    appendTerm(&p2, -4, 1);

    printf("Polynomial 1: ");
    displayPoly(p1);

    printf("Polynomial 2: ");
    displayPoly(p2);

    sum = addPoly(p1, p2);

    printf("Sum: ");
    displayPoly(sum);

    return 0;
}
