//  Problem 1: CPU Scheduling
//  You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU
//  interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there’s a
//  constraint: there has to be a gap of at least n intervals between two tasks with the same label. Return the
//  minimum number of CPU intervals required to complete all tasks. NOTE: You need to use priority queue.
//  Example 1: Input: tasks = [“A”,“A”,“A”,“B”,“B”,“B”], n = 2
//  Output: 8
//  Explanation: A possible sequence is: A → B → idle → A → B → idle → A → B.
//  After completing task A, you must wait two intervals before doing A again. The same applies to task B.
//  In the 3rd interval, neither A nor B can be done, so you idle. By the 4th interval, you can do A again as 2
//  intervals have passed.
//  Example 2: Input: tasks = [“A”,“C”,“A”,“B”,“D”,“B”], n = 1
//  Output: 6
//  Explanation: A possible sequence is: A → B → C → D → A → B.
//  With a cooling interval of 1, you can repeat a task after just one other task.
//  Example 3: Input: tasks = [“A”,“A”,“A”,“B”,“B”,“B”], n = 3
//  Output: 10
//  Explanation: A possible sequence is: A → B → idle → idle → A → B → idle → idle → A → B →.
//  There are only two types of tasks, A and B, which need to be separated by 3 intervals. This leads to idling
//  twice between repetitions of these tasks.


#include <stdio.h>

#define MAX 26

// ---------- Max Heap Functions ----------
void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void heapifyDown(int heap[], int size, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < size && heap[left] > heap[largest]) largest = left;
    if(right < size && heap[right] > heap[largest]) largest = right;

    if(largest != i) {
        swap(&heap[i], &heap[largest]);
        heapifyDown(heap, size, largest);
    }
}

void heapifyUp(int heap[], int i) {
    while(i > 0 && heap[(i-1)/2] < heap[i]) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

void push(int heap[], int *size, int val) {
    heap[*size] = val;
    (*size)++;
    heapifyUp(heap, *size-1);
}

int pop(int heap[], int *size) {
    if(*size == 0) return 0;
    int top = heap[0];
    heap[0] = heap[--(*size)];
    heapifyDown(heap, *size, 0);
    return top;
}

// ---------- Main Logic ----------
int leastInterval(char tasks[], int n) {
    int freq[26] = {0};
    for(int i = 0; tasks[i] != '\0'; i++) {
        freq[tasks[i] - 'A']++;
    }

    int heap[26], size = 0;
    for(int i = 0; i < 26; i++) {
        if(freq[i] > 0) push(heap, &size, freq[i]);
    }

    int time = 0;

    while(size > 0) {
        int temp[26], tSize = 0;

        // One cycle of (n+1)
        for(int i = 0; i <= n; i++) {
            if(size > 0) {
                int cnt = pop(heap, &size);
                cnt--;
                if(cnt > 0) temp[tSize++] = cnt;
            }

            time++;

            // If no tasks left in heap and no remaining ones to re-add → stop early
            if(size == 0 && tSize == 0) 
                break;
        }

        // Push back remaining tasks to heap
        for(int i = 0; i < tSize; i++) {
            push(heap, &size, temp[i]);
        }
    }

    return time;
}

// ---------- Test ----------
int main() {
    char tasks1[] = "AAABBB";
    int n1 = 2;
    printf("Output 1: %d\n", leastInterval(tasks1, n1)); // 8

    char tasks2[] = "ACABDB";
    int n2 = 1;
    printf("Output 2: %d\n", leastInterval(tasks2, n2)); // 6

    char tasks3[] = "AAABBB";
    int n3 = 3;
    printf("Output 3: %d\n", leastInterval(tasks3, n3)); // 10

    return 0;
}
