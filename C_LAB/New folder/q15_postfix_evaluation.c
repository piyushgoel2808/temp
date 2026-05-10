// Evaluate a postfix expression using a stack of operand values.
#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    // Store the next computed value on the stack.
    stack[++top] = value;
}

int pop() {
    // Return the current top value and move the pointer down.
    return stack[top--];
}

int main() {
    char expr[100];
    int values[26] = {0};
    int entered[26] = {0};
    int i;

    // Read the postfix expression using letters as variables.
    printf("Enter postfix expression (example: ab+cd-*ab/): ");
    scanf("%99s", expr);

    // Scan one character at a time and either push operands or compute results.
    for (i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        if (isalpha((unsigned char)ch)) {
            int idx = tolower((unsigned char)ch) - 'a';
            // Ask for a variable value only once the first time it appears.
            if (!entered[idx]) {
                printf("Enter value of %c: ", ch);
                scanf("%d", &values[idx]);
                entered[idx] = 1;
            }
            push(values[idx]);
        } else {
            if (top < 1) {
                printf("Invalid postfix expression.\n");
                return 0;
            }

            // Pop the right operand first, then the left operand.
            int b = pop();
            int a = pop();
            int result;

            switch (ch) {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    if (b == 0) {
                        printf("Division by zero error.\n");
                        return 0;
                    }
                    result = a / b;
                    break;
                case '%':
                    if (b == 0) {
                        printf("Modulo by zero error.\n");
                        return 0;
                    }
                    result = a % b;
                    break;
                default:
                    printf("Unsupported operator: %c\n", ch);
                    return 0;
            }
            push(result);
        }
    }

    if (top != 0) {
        printf("Invalid postfix expression.\n");
        return 0;
    }

    // The final remaining stack item is the expression result.
    printf("Result = %d\n", pop());
    return 0;
}
