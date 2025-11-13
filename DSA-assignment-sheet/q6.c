#include <stdio.h>
#include <stdlib.h>

// Define structure for linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to search for a value in the linked list
struct Node* search(struct Node* l, int x) {
    struct Node* temp = l;    
    while (temp != NULL) {
        if (temp->data == x)
            return temp;       
        temp = temp->next;     
    }
    return NULL;               
}

// Function to search and insert if not found
struct Node* srchinst(struct Node** l, int x) {
    struct Node* found = search(*l, x);   // search for x
    if (found != NULL)
        return found;                     // if found, return it

    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = *l;        
    *l = newNode;              
    return newNode;            
}

void display(struct Node* l) {
    struct Node* temp = l;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Example usage
int main() {
    struct Node* head = NULL;    // start with empty list

    srchinst(&head, 10);
    srchinst(&head, 20);
    srchinst(&head, 30);
    display(head);               // Output: 30 -> 20 -> 10 -> NULL

    // Search for existing node
    struct Node* p = search(head, 20);
    if (p != NULL)
        printf("Found: %d\n", p->data);
    else
        printf("Not found\n");

    // Insert new value if not found
    srchinst(&head, 40);
    display(head);               // Output: 40 -> 30 -> 20 -> 10 -> NULL

    return 0;
}
