//singly linked list (menu driven program)
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

// Insert at tail
node* insertTail(node* head, int val) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = NULL;

    if (head == NULL) return newnode;

    node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newnode;
    return head;
}

// Insert at index
node* insertAtIndex(node* head, int index, int val) {
    if (index < 0) {
        printf("Invalid index!\n");
        return head;
    }

    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = val;

    if (index == 0) { // insert at head
        newnode->next = head;
        return newnode;
    }

    node* temp = head;
    for (int i = 0; i < index - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Index out of bounds!\n");
        free(newnode);
        return head;
    }

    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}

// Insert by value (insert after first occurrence of given value)
node* insertByValue(node* head, int searchVal, int newVal) {
    node* temp = head;
    while (temp != NULL && temp->data != searchVal) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found!\n", searchVal);
        return head;
    }

    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = newVal;
    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}

// Delete by index (0-based)
node* deleteByIndex(node* head, int index) {
    if (head == NULL || index < 0) {
        printf("Invalid index!\n");
        return head;
    }

    if (index == 0) {
        node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    node* temp = head;
    for (int i = 0; i < index - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Index out of bounds!\n");
        return head;
    }

    node* del = temp->next;
    temp->next = del->next;
    free(del);
    return head;
}

// Delete by value (first occurrence)
node* deleteByValue(node* head, int val) {
    if (head == NULL) return NULL;

    if (head->data == val) {
        node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    node* temp = head;
    while (temp->next != NULL && temp->next->data != val) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Value %d not found!\n", val);
    } else {
        node* del = temp->next;
        temp->next = del->next;
        free(del);
    }

    return head;
}

// Display list
void display(node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    node* head = NULL;
    int choice, val, index, searchVal;

    do {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at Tail\n");
        printf("2. Insert at Index\n");
        printf("3. Insert by Value (after given value)\n");
        printf("4. Delete by Index\n");
        printf("5. Delete by Value\n");
        printf("6. Display List\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                head = insertTail(head, val);
                break;
            case 2:
                printf("Enter index and value: ");
                scanf("%d %d", &index, &val);
                head = insertAtIndex(head, index, val);
                break;
            case 3:
                printf("Enter existing value and new value: ");
                scanf("%d %d", &searchVal, &val);
                head = insertByValue(head, searchVal, val);
                break;
            case 4:
                printf("Enter index to delete: ");
                scanf("%d", &index);
                head = deleteByIndex(head, index);
                break;
            case 5:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                head = deleteByValue(head, val);
                break;
            case 6:
                display(head);
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 7);

    return 0;
}
