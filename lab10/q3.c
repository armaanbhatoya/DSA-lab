//  Problem 3: kth smallest and largest Key
//  Given the root of a binary search tree, and an integer k, return the kth smallest and largest of all the values
//  of the nodes in the tree

#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};


struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}


struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL)
        return newNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}


void kthSmallestUtil(struct TreeNode* root, int* k, int* result) {
    if (root == NULL || *k <= 0)
        return;

    kthSmallestUtil(root->left, k, result);
    (*k)--;  

    if (*k == 0) {
        *result = root->val;
        return;
    }

    kthSmallestUtil(root->right, k, result);
}


void kthLargestUtil(struct TreeNode* root, int* k, int* result) {
    if (root == NULL || *k <= 0)
        return;

    kthLargestUtil(root->right, k, result);
    (*k)--;

    if (*k == 0) {
        *result = root->val;
        return;
    }

    kthLargestUtil(root->left, k, result);
}


int main() {
    struct TreeNode* root = NULL;

   
    int values[] = {5, 3, 7, 2, 4, 6, 8};
    for (int i = 0; i < 7; i++)
        root = insert(root, values[i]);

    int k = 8;  
    int smallest = -1, largest = -1;

    int k1 = k, k2 = k; 
    kthSmallestUtil(root, &k1, &smallest);
    kthLargestUtil(root, &k2, &largest);

    printf("%dth Smallest Element: %d\n", k, smallest);
    printf("%dth Largest Element: %d\n", k, largest);

    return 0;
}
