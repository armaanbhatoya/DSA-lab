#include <stdio.h>
#include <string.h>

#define SIZE 100

// display current string
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
    deleted[(*dtop)++] = str[len - 1]; // push last char to deleted
    str[len - 1] = '\0';               // remove it
}

// redo = pop from deleted stack and append to string
void redo(char str[], char deleted[], int *dtop) {
    if (*dtop == 0) {
        printf("Nothing to redo!\n");
        return;
    }
    char ch = deleted[--(*dtop)]; // pop last deleted
    int len = strlen(str);
    str[len] = ch;
    str[len + 1] = '\0';
}

int main() {
    char str[SIZE], deleted[SIZE];
    int dtop = 0; // top pointer for deleted stack

    printf("Enter word: ");
    scanf("%s", str);

    display(str);

    // demo
    undo(str, deleted, &dtop);
    printf("After undo: ");
    display(str);

    redo(str, deleted, &dtop);
    printf("After redo: ");
    display(str);

    return 0;
}
