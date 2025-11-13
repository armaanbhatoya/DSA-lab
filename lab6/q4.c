//E-commerce browsing history
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    int id;
    char name[50];
    float price;
    struct Product *prev, *next;
};

struct Product *head = NULL, *tail = NULL, *current = NULL;

// Function to add new product at end
void addProduct(int id, char name[], float price) {
    struct Product *newNode = (struct Product *)malloc(sizeof(struct Product));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->price = price;
    newNode->next = NULL;
    newNode->prev = tail;

    if (head == NULL)
        head = newNode;
    else
        tail->next = newNode;

    tail = newNode;
    current = tail; // last viewed product
}

// Move backward
void moveBackward() {
    if (current != NULL && current->prev != NULL) {
        current = current->prev;
        printf("Moved back to: %s (%.2f)\n", current->name, current->price);
    } else {
        printf("No previous product!\n");
    }
}

// Move forward
void moveForward() {
    if (current != NULL && current->next != NULL) {
        current = current->next;
        printf("Moved forward to: %s (%.2f)\n", current->name, current->price);
    } else {
        printf("No next product!\n");
    }
}

// Delete products with price < 500
void deleteLowPrice() {
    struct Product *temp = head;
    while (temp != NULL) {
        struct Product *next = temp->next;
        if (temp->price < 500) {
            if (temp->prev)
                temp->prev->next = temp->next;
            else
                head = temp->next;
            if (temp->next)
                temp->next->prev = temp->prev;
            else
                tail = temp->prev;
            free(temp);
        }
        temp = next;
    }
}

// Display list
void display() {
    struct Product *temp = head;
    printf("\nBrowsing History:\n");
    while (temp != NULL) {
        printf("ID: %d | %s | Price: %.2f\n", temp->id, temp->name, temp->price);
        temp = temp->next;
    }
}

int main() {
    addProduct(1, "Laptop", 60000);
    addProduct(2, "Mouse", 400);
    addProduct(3, "Keyboard", 700);
    addProduct(4, "Cable", 200);

    display();

    printf("\n--- Moving ---\n");
    moveBackward();
    moveBackward();
    moveForward();

    printf("\n--- Deleting products with price < 500 ---\n");
    deleteLowPrice();
    display();

    return 0;
}
