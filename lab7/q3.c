// Problcm 3: Evaluate Postfix Expression Calculator
// Design a postfix expression (Reverse Polish Notation) using a stack
// • Read a postfix expression consisting of integers and operators (4 — •
// • Use a stack to evaluate the expression and print the result.
// • Example: Input 5 1 2 + 4 • + 3 should output the correct arithmetic result.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // for isdigit()

#define MAX 100

int stack[MAX];
int top = -1;

// Function to push an element
void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        exit(1);
    }
    stack[++top] = x;
}

// Function to pop an element
int pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    return stack[top--];
}

int main() {
    char exp[100];
    int i, val1, val2, res;

    printf("Enter postfix expression (single-digit numbers, no spaces): ");
    scanf("%s", exp);  // read input like 512+4*+3-

    for (i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        // If it's a number, push it
        if (isdigit(ch)) {
            push(ch - '0');  // convert char → int
        }
        // If it's an operator, pop two operands and calculate
        else {
            val1 = pop();
            val2 = pop();

            switch (ch) {
                case '+': res = val2 + val1; break;
                case '-': res = val2 - val1; break;
                case '*': res = val2 * val1; break;
                case '/': res = val2 / val1; break;
                default:
                    printf("Invalid operator '%c'\n", ch);
                    exit(1);
            }
            push(res);
        }
    }

    // Final result
    res = pop();

    if (top != -1) {
        printf("Invalid Expression: Extra operands remaining!\n");
    } else {
        printf("Result = %d\n", res);
    }

    return 0;
}
