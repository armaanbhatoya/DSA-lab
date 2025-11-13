#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

// Stack structure
struct Stack {
    char arr[MAX];
    int top;
};

// Initialize stack
void initStack(struct Stack* s) {
    s->top = -1;
}

// Push character onto stack
void push(struct Stack* s, char c) {
    if (s->top < MAX - 1) {
        s->arr[++(s->top)] = c;
    }
}

// Pop character from stack
char pop(struct Stack* s) {
    if (s->top >= 0)
        return s->arr[(s->top)--];
    return '\0';
}

// Function to check if a string is palindrome
bool isPalindrome(char str[]) {
    struct Stack s;
    initStack(&s);

    int len = strlen(str);

   
    for (int i = 0; i < len; i++) {
        push(&s, str[i]);
    }


    for (int i = 0; i < len; i++) {
        char popped = pop(&s);
        if (str[i] != popped)
            return false;  
    }

    return true;  
}

// Main function to test
int main() {
    char str[MAX];
    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str))
        printf("The string '%s' is a palindrome.\n", str);
    else
        printf("The string '%s' is not a palindrome.\n", str);

    return 0;
}
