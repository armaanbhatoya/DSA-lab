// Problem 2: Railway Coach Reordering
// (2 marks)
// A railway yard has a stack-based siding track where coaches can be temporarily parked to reorder them
// before attaching to thc tram.
// • Given an incoming sequence of coaches, stimulates whether the desired output sequence can be achieved
// using a stack.
// • Write an algorithm to check if a target sequence is possible.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack implementation
typedef struct {
    int data[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, int val) {
    if (!isFull(s))
        s->data[++(s->top)] = val;
}

int pop(Stack *s) {
    if (!isEmpty(s))
        return s->data[(s->top)--];
    return -1;
}

int peek(Stack *s) {
    if (!isEmpty(s))
        return s->data[s->top];
    return -1;
}

// Function to check if reordering is possible
int canReorder(int n, int target[]) {
    Stack s;
    init(&s);
    int nextIncoming = 1; // coaches arriving in order
    int i = 0;            // index for target array

    while (nextIncoming <= n || !isEmpty(&s)) {
        if (!isEmpty(&s) && peek(&s) == target[i]) {
            pop(&s);
            i++;
        } else if (nextIncoming <= n) {
            push(&s, nextIncoming);
            nextIncoming++;
        } else {
            break;
        }
    }

    return i == n;
}

// Main function
int main() {
    int n;

    printf("Enter number of coaches: ");
    scanf("%d", &n);

    int target[n];
    printf("Enter target sequence: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &target[i]);

    if (canReorder(n, target))
        printf("Yes, possible.\n");
    else
        printf("No, not possible.\n");

    return 0;
}
