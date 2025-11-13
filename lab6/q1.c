// train compartments

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int compNo;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int compNo) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->compNo = compNo;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertFront(struct Node* head, int compNo) {
    struct Node* newNode = createNode(compNo);
    if (head == NULL) {
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    return newNode;  
}

struct Node* insertEnd(struct Node* head, int compNo) {
    struct Node* newNode = createNode(compNo);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;   
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("No compartments in the train.\n");
        return;
    }
    printf("Compartments from front to end: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->compNo);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* start = NULL;
    int choice, compNo;

    while (1) {
        printf("\n    Train Menu    \n");
        printf("1. Insert compartment at front\n");
        printf("2. Insert compartment at end\n");
        printf("3. Display compartments\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter compartment number: ");
                scanf("%d", &compNo);
                start = insertFront(start, compNo);
                break;

            case 2:
                printf("Enter compartment number: ");
                scanf("%d", &compNo);
                start = insertEnd(start, compNo);
                break;

            case 3:
                display(start);
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
