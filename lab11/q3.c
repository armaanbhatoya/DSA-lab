//  Problem 3: kth smallest and largest Key
//  Given the root of a binary tree, and an integer k, return the kth smallest and largest of all the values of the
//  nodes in the tree using heap

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

int countNodes(struct Node* root) {
    if(root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void fillArray(struct Node* root, int arr[], int *index) {
    if(root == NULL) return;
    arr[(*index)++] = root->data;
    fillArray(root->left, arr, index);
    fillArray(root->right, arr, index);
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < n && arr[l] < arr[smallest])
        smallest = l;
    if(r < n && arr[r] < arr[smallest])
        smallest = r;

    if(smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < n && arr[l] > arr[largest])
        largest = l;
    if(r < n && arr[r] > arr[largest])
        largest = r;

    if(largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

int kthSmallest(struct Node* root, int k) {
    int n = countNodes(root);
    int arr[n], index = 0;

    fillArray(root, arr, &index);

  
    for(int i = n/2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    for(int i = 1; i < k; i++) {
        arr[0] = arr[n-1];
        n--;
        minHeapify(arr, n, 0);
    }

    return arr[0];
}

int kthLargest(struct Node* root, int k) {
    int n = countNodes(root);
    int arr[n], index = 0;

    fillArray(root, arr, &index);

    for(int i = n/2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    for(int i = 1; i < k; i++) {
        arr[0] = arr[n-1];
        n--;
        maxHeapify(arr, n, 0);
    }

    return arr[0];
}

int main() {
 
    struct Node* root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(8);
    root->left->left = newNode(1);
    root->left->right = newNode(4);
    root->right->left = newNode(7);
    root->right->right = newNode(10);

    int k;
    printf("enter k : ");
    scanf("%d", &k);

    printf("%d-th smallest = %d\n", k, kthSmallest(root, k));
    printf("%d-th largest = %d\n", k, kthLargest(root, k));

    return 0;
}
