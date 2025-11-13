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
