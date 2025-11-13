//Train Coach Coupling

#include <stdio.h>
#include <stdlib.h>


typedef struct Coach {
    int coachNumber;
    struct Coach *next;
} Coach;

// Head pointer (start of the train)
Coach *head = NULL;

// Function to add a coach at the end (couple)
void addCoach(int number) {
    Coach *newCoach = (Coach *)malloc(sizeof(Coach));
    newCoach->coachNumber = number;
    newCoach->next = NULL;

    if (head == NULL) {
        head = newCoach;
        printf("Coach %d coupled as the first coach.\n", number);
    } else {
        Coach *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newCoach;
        printf("Coach %d coupled to the train.\n", number);
    }
}

// Function to remove last coach (decouple)
void removeCoach() {
    if (head == NULL) {
        printf("No coaches to remove. Train is empty!\n");
        return;
    }

    Coach *temp = head;
    Coach *prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) { 
        printf("Coach %d decoupled. Train is now empty.\n", temp->coachNumber);
        free(temp);
        head = NULL;
    } else {
        printf("Coach %d decoupled from the train.\n", temp->coachNumber);
        free(temp);
        prev->next = NULL;
    }
}


void displayTrain() {
    if (head == NULL) {
        printf("No coaches in the train.\n");
        return;
    }

    Coach *temp = head;
    printf("Current train: ");
    while (temp != NULL) {
        printf("[Coach %d]", temp->coachNumber);
        if (temp->next != NULL)
            printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    int choice, num;

    while (1) {
        printf("\n--- Train Coach Coupling System ---\n");
        printf("1. Add a Coach\n");
        printf("2. Remove a Coach\n");
        printf("3. Display Train\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter coach number to add: ");
                scanf("%d", &num);
                addCoach(num);
                break;
            case 2:
                removeCoach();
                break;
            case 3:
                displayTrain();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
