// Problem 3: Root to path
//  Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the
//  node values in the path equals targetSum. Each path should be returned as a list of the node values, not node
//  references.
//  A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no
//  children

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};


struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}


void printPath(int path[], int pathLen) {
    for (int i = 0; i < pathLen; i++)
        printf("%d ", path[i]);
    printf("\n");
}


void findPaths(struct Node* root, int path[], int pathLen, int targetSum) {
    if (root == NULL)
        return;

   
    path[pathLen] = root->data;
    pathLen++;

    
    if (root->left == NULL && root->right == NULL) {
        
        int sum = 0;
        for (int i = 0; i < pathLen; i++)
            sum += path[i];

        if (sum == targetSum) {
            printf("Path with sum %d: ", targetSum);
            printPath(path, pathLen);
        }
    } else {
        
        findPaths(root->left, path, pathLen, targetSum);
        findPaths(root->right, path, pathLen, targetSum);
    }
}

int main() {
   
    struct Node* root = newNode(5);
    root->left = newNode(4);
    root->right = newNode(8);
    root->left->left = newNode(11);
    root->left->left->left = newNode(7);
    root->left->left->right = newNode(2);
    root->right->left = newNode(13);
    root->right->right = newNode(4);
    root->right->right->left = newNode(5);
    root->right->right->right = newNode(1);

    int targetSum;
    printf("Enter target sum: ");
    scanf("%d", &targetSum);

    int path[100];
    printf("\nAll required paths with sum = %d:\n", targetSum);
    findPaths(root, path, 0, targetSum);

    return 0;
}
