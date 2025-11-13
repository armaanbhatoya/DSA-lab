// Problem 6: Largest Rectangle in Histogram (Skyline Problem)
// A city skyline is represented by bar heights in a histogram.
// • Use a stack-based algorithm to compute the largest rectangle that can be formed under the skyline.
// • Example: Given heights [6, 2, 5, 4, 5, 1, 6], the maximum rectangle area is 12.


#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int lrgst_rect_area(int arr[], int n) {
    int *st = (int *)malloc(n * sizeof(int));  // stack for indices
    int top = -1;                              // empty stack
    int maxArea = 0;

    for (int i = 0; i <= n; i++) {
        // current height (0 when i == n to flush stack)
        int currHeight = (i == n) ? 0 : arr[i];

        // while stack not empty and current height < height at top of stack
        while (top != -1 && arr[st[top]] > currHeight) {
            int element = st[top--];  // pop index
            int nse = i;              // next smaller element index
            int pse = (top == -1) ? -1 : st[top];  // prev smaller element index

            int width = nse - pse - 1;
            int area = arr[element] * width;

            maxArea = max(maxArea, area);
        }

        // push current index
        st[++top] = i;
    }

    free(st);
    return maxArea;
}

int main() {
    int arr[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = lrgst_rect_area(arr, n);
    printf("Maximum Rectangle Area = %d\n", result);

    return 0;
}
