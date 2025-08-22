//undo redo and store in stack

#include <stdio.h>
#include <string.h>

#define SIZE 100


void display(char str[]) {
    printf("%s\n", str);
}

// undo = remove last character and push into deleted stack
void undo(char str[], char deleted[], int *dtop) {
    int len = strlen(str);
    if (len == 0) {
        printf("Nothing to undo!\n");
        return;
    }
    deleted[(*dtop)++] = str[len - 1]; 
    str[len - 1] = '\0';               
}

// redo = pop from deleted stack and append to string
void redo(char str[], char deleted[], int *dtop) {
    if (*dtop == 0) {
        printf("Nothing to redo!\n");
        return;
    }
    char ch = deleted[--(*dtop)]; 
    int len = strlen(str);
    str[len] = ch;
    str[len + 1] = '\0';
}

int main() {
    char str[SIZE], deleted[SIZE];
    int dtop = 0; // top pointer for deleted stack

    printf("Enter word: ");
    scanf("%s", str);

    int choice;
    while (1)
    {   printf("menu----\n1.undo\n2.redo\n3.display\n4.exit\nenter choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            undo(str,deleted,&dtop);
            break;
        case 2:
            redo(str,deleted,&dtop);
            break;
        case 3:
            display(str);
            break;
        case 4:
            return 0;
        default:
            printf("INVALID CHOICE\n");
            break;
        }
    }
    


    return 0;
}
