//  Problem 4: Sorting
//  You are given with n integers (not necessarily sorted). You need to sort them using tree. Write the
//  comparison of your algorithm with respect to Quick Sort and Merge Sort.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return newNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}


int main() {
    int arr[] = {5, 3, 7, 2, 4, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Node* root = NULL;

    
    for (int i = 0; i < n; i++)
        root = insert(root, arr[i]);

    printf("Sorted order using Tree Sort: ");
    inorder(root);
    printf("\n");

    return 0;
}




// Comparison Table (Very Simple)
// Method	Best / Average Time	Worst Time	Extra Space	Notes
// Tree Sort	O(n log n)	O(n²)	O(n)	Works well only if tree is balanced
// Quick Sort	O(n log n)	O(n²)	O(log n)	Very fast in practice but worst case slow
// Merge Sort	O(n log n)	O(n log n)	O(n)	Always fast but uses extra memory
// Simple Explanation

// Tree Sort is good if the tree stays balanced. But if elements are already sorted, the tree becomes tall and it becomes slow.

// Quick Sort is usually the fastest in real use, but in worst cases it also becomes slow.

// Merge Sort is always fast, but needs extra space in memory.

// Conclusion (1–2 lines)

// Tree Sort is easy to understand but not always efficient.
// Quick Sort is generally faster, and Merge Sort is always reliable but uses more memory.
