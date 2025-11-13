// Circular Bus Service
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

// Function to create a new node
struct Node* createNode(char *name) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->next = newNode->prev = NULL;
    return newNode;
}

// Function to insert a stop at a given position
void insertStop(char *name, int position) {
    struct Node *newNode = createNode(name);

    if (head == NULL) { // empty list
        head = newNode;
        head->next = head->prev = head;
        return;
    }

    if (position == 1) { // insert at beginning
        struct Node *last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
        head = newNode;
        return;
    }

    struct Node *temp = head;
    int i = 1;
    while (i < position - 1 && temp->next != head) {
        temp = temp->next;
        i++;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

// Function to delete a stop by name
void deleteStop(char *name) {
    if (head == NULL) {
        printf("No stops available.\n");
        return;
    }

    struct Node *temp = head, *toDelete = NULL;

    do {
        if (strcmp(temp->name, name) == 0) {
            toDelete = temp;
            break;
        }
        temp = temp->next;
    } while (temp != head);

    if (toDelete == NULL) {
        printf("Stop '%s' not found.\n", name);
        return;
    }

    if (toDelete->next == toDelete) { // only one node
        head = NULL;
    } else {
        struct Node *prevNode = toDelete->prev;
        struct Node *nextNode = toDelete->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        if (toDelete == head)
            head = nextNode;
    }

    free(toDelete);
    printf("Stop '%s' deleted successfully.\n", name);
}

// Traverse forward
void displayForward() {
    if (head == NULL) {
        printf("No bus stops.\n");
        return;
    }

    struct Node *temp = head;
    printf("Forward traversal: ");
    do {
        printf("%s -> ", temp->name);
        temp = temp->next;
    } while (temp != head);
    printf("(back to start)\n");
}

// Traverse backward
void displayBackward() {
    if (head == NULL) {
        printf("No bus stops.\n");
        return;
    }

    struct Node *temp = head->prev;
    printf("Backward traversal: ");
    do {
        printf("%s -> ", temp->name);
        temp = temp->prev;
    } while (temp != head->prev);
    printf("(back to start)\n");
}

int main() {
    insertStop("StopA", 1);
    insertStop("StopB", 2);
    insertStop("StopC", 3);
    insertStop("StopD", 2);

    displayForward();
    displayBackward();

    deleteStop("StopC");
    displayForward();

    return 0;
}

