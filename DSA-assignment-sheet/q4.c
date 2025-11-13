#include <stdio.h>
#include <stdlib.h>

#define MAX 10   // total array size for both stacks

// Global variables
int stack[MAX];
int top1 = -1;      // stack 1 starts from left end
int top2 = MAX;     // stack 2 starts from right end

// Function to push element in stack 1
void push1(int value) {
    if (top1 + 1 == top2) {
        printf("Stack Overflow! Cannot push %d into Stack 1\n", value);
    } else {
        top1++;
        stack[top1] = value;
        printf("%d pushed into Stack 1\n", value);
    }
}

// Function to push element in stack 2
void push2(int value) {
    if (top2 - 1 == top1) {
        printf("Stack Overflow! Cannot push %d into Stack 2\n", value);
    } else {
        top2--;
        stack[top2] = value;
        printf("%d pushed into Stack 2\n", value);
    }
}

// Function to pop element from stack 1
int pop1() {
    if (top1 == -1) {
        printf("Stack 1 Underflow!\n");
        return -1;
    } else {
        int val = stack[top1];
        top1--;
        printf("%d popped from Stack 1\n", val);
        return val;
    }
}

// Function to pop element from stack 2
int pop2() {
    if (top2 == MAX) {
        printf("Stack 2 Underflow!\n");
        return -1;
    } else {
        int val = stack[top2];
        top2++;
        printf("%d popped from Stack 2\n", val);
        return val;
    }
}

// Function to display both stacks
void display() {
    int i;

    printf("\nStack 1 (bottom to top): ");
    if (top1 == -1)
        printf("Empty");
    else {
        for (i = 0; i <= top1; i++)
            printf("%d ", stack[i]);
    }

    printf("\nStack 2 (bottom to top): ");
    if (top2 == MAX)
        printf("Empty");
    else {
        for (i = MAX - 1; i >= top2; i--)
            printf("%d ", stack[i]);
    }
    printf("\n");
}

// Main function to demonstrate
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Two Stacks in One Array ---\n");
        printf("1. Push in Stack 1\n");
        printf("2. Push in Stack 2\n");
        printf("3. Pop from Stack 1\n");
        printf("4. Pop from Stack 2\n");
        printf("5. Display both stacks\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push in Stack 1: ");
                scanf("%d", &value);
                push1(value);
                break;
            case 2:
                printf("Enter value to push in Stack 2: ");
                scanf("%d", &value);
                push2(value);
                break;
            case 3:
                pop1();
                break;
            case 4:
                pop2();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
