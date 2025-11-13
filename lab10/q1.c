// // q1 and q3 and result of q4 write in file
// Problem 1: Mirror Tree
//  Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).


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
    node->left = node->right = NULL;
    return node;
}

// Insert node by choosing left or right path
void insert(struct TreeNode** root, int val) {
    if (*root == NULL) {
        *root = newNode(val);
        printf("Root created.\n");
        return;
    }
    struct TreeNode* temp = *root;
    char ch;
    while (1) {
        printf("At node %d, go Left(l) or Right(r)? ", temp->val);
        scanf(" %c", &ch);
        if (ch == 'l') {
            if (temp->left == NULL) { temp->left = newNode(val); break; }
            temp = temp->left;
        } else if (ch == 'r') {
            if (temp->right == NULL) { temp->right = newNode(val); break; }
            temp = temp->right;
        } else printf("Invalid! ");
    }
}

// Mirror Check
int isMirror(struct TreeNode* t1, struct TreeNode* t2) {
    if (!t1 && !t2) return 1;
    if (!t1 || !t2) return 0;
    return (t1->val == t2->val) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

int isSymmetric(struct TreeNode* root) {
    if (!root) return 1;
    return isMirror(root->left, root->right);
}

int main() {
    struct TreeNode* root = NULL;
    int choice, val;

    while (1) {
        printf("\n1.Insert Node\n2.Check Symmetric\n3.Exit\nEnter: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Value: ");
                scanf("%d", &val);
                insert(&root, val);
                break;
            case 2:
                printf(isSymmetric(root) ? "Tree is Symmetric\n" : "Tree is Not Symmetric\n");
                break;
            case 3:
                exit(0);
        }
    }
}
