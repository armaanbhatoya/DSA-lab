#include <stdio.h>
#include <stdlib.h>
#define SIZE 5  

int queue[SIZE];
int front = -1, rear = -1;

int isFull() {
    return rear == SIZE - 1;
}

int isEmpty() {
    return front == -1 || front > rear;
}

void enqueue(int value) {
    if (isFull()) {
        printf("\nQueue is Full!\n");
    } else {
        if (front == -1)
            front = 0;
        queue[++rear] = value;
        printf("\n%d inserted into the queue.\n", value);
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("\nQueue is Empty!\n");
    } else {
        printf("\n%d removed from the queue.\n", queue[front++]);
        if (front > rear)
            front = rear = -1; 
    }
}

void display() {
    if (isEmpty()) {
        printf("\nQueue is Empty!\n");
    } else {
        printf("\nQueue elements: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n Queue Menu \n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("----------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}
