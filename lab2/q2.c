// store contacts detail in sorted order

#include <stdio.h>
#include <string.h>

struct Contact_details {
    char name[20];
    long long int phn_no;
};

void sort_contacts(struct Contact_details arr[], int n) {
    struct Contact_details temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i].name, arr[j].name) > 0) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void display_contacts(struct Contact_details arr[], int n) {
    if (n == 0) {
        printf("\nNo contacts available.\n\n");
        return;
    }
    printf("\n--- Contact List ---\n");
    for (int i = 0; i < n; i++) {
        printf("Contact %d:\n", i + 1);
        printf("Name: %s\n", arr[i].name);
        printf("Phone no.: %lld\n", arr[i].phn_no);
    }
    printf("\n");
}

void add_contact(struct Contact_details arr[], int *n) {
    printf("\nEnter contact details:->\n");
    printf("Name: ");
    scanf(" %s", arr[*n].name);
    printf("Phone no.: ");
    scanf("%lld", &arr[*n].phn_no);
    (*n)++;
    sort_contacts(arr, *n);
    printf("Contact added successfully!\n");
}

int delete_contact(struct Contact_details arr[], int *n, const char *name) {
    int index = -1;
    for (int i = 0; i < *n; i++) {
        if (strcmp(arr[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        return 0;
    }
    for (int i = index; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    return 1;
}

int main() {
    struct Contact_details arr[100];
    int n = 0;
    int choice;
    char del_name[20];

    while (1) {
        printf("\n===== Contact Manager =====\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Delete Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact(arr, &n);
                break;
            case 2:
                display_contacts(arr, n);
                break;
            case 3:
                printf("Enter name of contact to delete: ");
                scanf(" %s", del_name);
                if (delete_contact(arr, &n, del_name)) {
                    printf("Contact deleted successfully.\n");
                } else {
                    printf("Contact not found.\n");
                }
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
