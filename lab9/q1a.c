// using arrays

#include <stdio.h>

#define MAX 100

void inorder(int arr[], int index, int n) {
    if (index >= n)
        return;

    // L
    inorder(arr, 2 * index + 1, n);

    // root
    printf("%d ", arr[index]);

    // R
    inorder(arr, 2 * index + 2, n);
}

int main() {
    int n, arr[MAX];
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Inorder traversal of Binary Tree : ");
    inorder(arr, 0, n);

    return 0;
}
