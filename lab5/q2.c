// Ticket queue

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *link;
};

// Print the queue
void print(struct Node* start) {
    struct Node *curr = start;
    while (curr != NULL) {
        printf("%d->", curr->data);
        curr = curr->link;
    }
    printf("NULL\n");
}

// Add VIP: always goes to the front
struct Node* addVIP(struct Node *start, int *cnt) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return start;
    }

    if (start == NULL) {
        newNode->data = 1;
        newNode->link = NULL;
        start = newNode;
    } else {
        newNode->link = start;
        newNode->data = 1;
        start = newNode;

        // Shift everyone else back by +1
        struct Node *curr = start->link;
        while (curr != NULL) {
            curr->data = (curr->data) + 1;
            curr = curr->link;
        }
    }
    (*cnt)++;
    return start;
}

// Add Not VIP: always goes to the end
struct Node* addNotVIP(struct Node *start, int *cnt) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return start;
    }

    (*cnt)++;
    newNode->data = *cnt;
    newNode->link = NULL;

    if (start == NULL) {
        return newNode;
    } else {
        struct Node *curr = start;
        while (curr->link != NULL) curr = curr->link;
        curr->link = newNode;
    }
    return start;
}

// Add Known-to: goes to given position
struct Node* addKnownTo(struct Node *start, int *cnt) {
    if (start == NULL) {
        printf("Queue is empty. Adding as first node instead.\n");
        return addNotVIP(start, cnt);
    }

    int pos;
    printf("Enter position where you want to go: ");
    scanf("%d", &pos);

    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return start;
    }

    // Insert at head if pos == 1
    if (pos == 1) {
        newNode->data = 1;
        newNode->link = start;
        start = newNode;

        // shift others
        struct Node *curr = newNode->link;
        while (curr != NULL) {
            curr->data++;
            curr = curr->link;
        }
        (*cnt)++;
        return start;
    }

    struct Node *curr = start;
    for (int i = 1; i < pos - 1 && curr->link != NULL; i++) {
        curr = curr->link;
    }

    // Insert after `curr`
    newNode->link = curr->link;
    curr->link = newNode;

    // Assign ticket number
    newNode->data = curr->data + 1;

    // Shift others back
    curr = newNode->link;
    while (curr != NULL) {
        curr->data++;
        curr = curr->link;
    }

    (*cnt)++;
    return start;
}

int main() {
    struct Node *start = NULL;
    int cnt = 0;
    while (1) {
        printf("\n1: VIP, 2: Not VIP, 3: Known To, 4: Print Queue, 0: Exit -> ");
        int ch;
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                start = addVIP(start, &cnt);
                break;
            case 2:
                start = addNotVIP(start, &cnt);
                break;
            case 3:
                start = addKnownTo(start, &cnt);
                break;
            case 4:
                print(start);
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
