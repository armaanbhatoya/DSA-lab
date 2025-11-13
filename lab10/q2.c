//  Problem 2: Minimum Depth
//  Given a binary tree, find its minimum depth. The minimum depth is the number of nodes along the shortest
//  path from the root node down to the nearest leaf node. Note: A leaf is a node with no children.

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

int minDepth(struct TreeNode* root){
    if(root == NULL) return 0;
    if(root->left == NULL) return 1+minDepth(root->right);
    if(root->right == NULL) return 1+minDepth(root->left);
    
    int leftdepth = minDepth(root->left);
    int rightdepth = minDepth(root->right);
    return 1 + (leftdepth<rightdepth ? leftdepth : rightdepth);
}

int main(){
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(5);
    root->right->left->left = newNode(7);
    root->left->left = newNode(4);

    printf("min depth = %d\n",minDepth(root));
    return 0;
}