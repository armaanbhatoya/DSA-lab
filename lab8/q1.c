// You are given an integer array nums, and there is a sliding window of size k which moves from the very left
//  of the array to the very right. You can only see the k numbers inside the window at a time. Each time the
//  sliding window moves right by one position. Your task is to return an array containing the maximum element
//  in the sliding window for each position as it moves from left to right
#include <stdio.h>
#include <stdlib.h>

// Deque structure
typedef struct {
    int *data;
    int front, rear;
} Deque;

// Initialize deque
Deque* createDeque(int size) {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->data = (int*)malloc(size * sizeof(int));
    dq->front = 0;
    dq->rear = -1;
    return dq;
}

// Check if deque is empty
int isEmpty(Deque* dq) {
    return dq->front > dq->rear;
}

// Push index at rear
void pushBack(Deque* dq, int val) {
    dq->data[++dq->rear] = val;
}

// Pop index from rear
void popBack(Deque* dq) {
    dq->rear--;
}

// Pop index from front
void popFront(Deque* dq) {
    dq->front++;
}

// Get front element (index)
int front(Deque* dq) {
    return dq->data[dq->front];
}

// Get back element (index)
int back(Deque* dq) {
    return dq->data[dq->rear];
}

// Sliding window maximum
void maxSlidingWindow(int *nums, int n, int k) {
    if (n == 0 || k == 0) return;

    Deque* dq = createDeque(n);
    int *result = (int*)malloc((n - k + 1) * sizeof(int));
    int idx = 0;

    for (int i = 0; i < n; i++) {
        // Remove elements smaller than current from rear
        while (!isEmpty(dq) && nums[back(dq)] <= nums[i])
            popBack(dq);

        // Add current element index
        pushBack(dq, i);

        // Remove elements out of the window
        if (front(dq) <= i - k)
            popFront(dq);

        // Add max to result after first window
        if (i >= k - 1)
            result[idx++] = nums[front(dq)];
    }

    printf("Sliding Window Maximums: ");
    for (int i = 0; i < idx; i++)
        printf("%d ", result[i]);
    printf("\n");

    free(result);
    free(dq->data);
    free(dq);
}

int main() {
    int nums[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int n = sizeof(nums) / sizeof(nums[0]);
    int k = 3;

    maxSlidingWindow(nums, n, k);
    return 0;
}
