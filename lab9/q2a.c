//  Create a Binary Search Tree using Linked list and arrays, separately. Store n different integers in the binary search tree

// using arrays

#include <stdio.h>

#define MAX 100

int bst[MAX]; 
int used[MAX]; 

void insert(int index, int value) {
    if (index >= MAX) {
        printf("Tree is full!\n");
        return;
    }

    if (!used[index]) {
        bst[index] = value;
        used[index] = 1;
    } else {
        if (value < bst[index])
            insert(2 * index + 1, value);
        else if (value > bst[index])
            insert(2 * index + 2, value);
    }
}

void inorder(int index) {
    if (index >= MAX || !used[index])
        return;

    inorder(2 * index + 1);
    printf("%d ", bst[index]);
    inorder(2 * index + 2);
}

int main() {
    int n, val;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insert(0, val); 
    }

    printf("Inorder traversal of BST : ");
    inorder(0);

    return 0;
}
