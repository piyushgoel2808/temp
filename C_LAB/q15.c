#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    stack[++top] = value;
}

int pop() {
    return stack[top--];
}

int main() {
    char expr[100];
    int values[26] = {0};
    int entered[26] = {0};
    int i;

    printf("Enter postfix expression (example: ab+cd-*ab/): ");
    scanf("%99s", expr);

    for (i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        if (isalpha((unsigned char)ch)) {
            int idx = tolower((unsigned char)ch) - 'a';
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

    printf("Result = %d\n", pop());
    return 0;
}
