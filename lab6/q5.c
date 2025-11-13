//Hospital patient priority queue
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient {
    int id;
    char name[50];
    int priority; // 1 = highest
    struct Patient *prev, *next;
};

struct Patient *head = NULL;

// Insert according to priority
void insertPatient(int id, char name[], int priority) {
    struct Patient *newNode = (struct Patient *)malloc(sizeof(struct Patient));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->priority = priority;
    newNode->next = newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Patient *temp = head;
    while (temp != NULL && temp->priority <= priority)
        temp = temp->next;

    if (temp == head) { // insert at beginning
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else if (temp == NULL) { // insert at end
        struct Patient *tail = head;
        while (tail->next != NULL) tail = tail->next;
        tail->next = newNode;
        newNode->prev = tail;
    } else { // insert before temp
        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;
    }
}

// Delete patient (after surgery)
void deletePatient() {
    if (head == NULL) {
        printf("No patients in queue!\n");
        return;
    }
    struct Patient *temp = head;
    printf("Patient %s (ID: %d) surgery completed.\n", temp->name, temp->id);
    head = head->next;
    if (head)
        head->prev = NULL;
    free(temp);
}

// Display patients
void displayPatients() {
    struct Patient *temp = head;
    printf("\nPatient Priority Queue:\n");
    while (temp != NULL) {
        printf("ID: %d | Name: %s | Priority: %d\n", temp->id, temp->name, temp->priority);
        temp = temp->next;
    }
}

int main() {
    insertPatient(101, "Alice", 3);
    insertPatient(102, "Bob", 1);
    insertPatient(103, "Charlie", 4);
    insertPatient(104, "David", 2);

    displayPatients();

    printf("\nAfter Surgery:\n");
    deletePatient();
    displayPatients();

    return 0;
}
