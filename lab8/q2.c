// You have n tasks and m workers. Each task needs some amount of strength to do, given by the array tasks
//  (where the strength needed for task i is tasks[i]). Each worker has some strength given by the array workers
//  (worker j has strength workers[j]).
//  • Aworker can only do one task.
//  • Aworker can only do a task if their strength is at least as much as the task needs.
//  You also have pills, and each pill increases a worker’s strength by a fixed amount strength. You can give each
//  worker at most one pill (or no pill). You decide who gets the pills.
//  Question: Given the tasks, workers, number of pills, and strength each pill provides, what is the largest
//  number of tasks that can be completed?
//  Example:
//  Input: tasks = [3,2,1], workers = [0,3,3], pills = 1, strength = 1
//  Output: 3
//  Explanation: We can assign the magical pill and tasks as follows:- Give the magical pill to worker 0.
// Assign worker 0 to task 2 (0 + 1 ¿= 1)- Assign worker 1 to task 1 (3 ¿= 2)- Assign worker 2 to task 0 (3 ¿= 3)
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int front, rear;
} Queue;

void init(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front > q->rear;
}

void enqueue(Queue *q, int val) {
    q->rear++;
    q->data[q->rear] = val;
}

int dequeue(Queue *q) {
    return q->data[q->front++];
}

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int tasks[] = {3, 2, 1};
    int workers[] = {0, 3, 3};
    int n = 3, m = 3;
    int pills = 1, strength = 1;
    int completed = 0;

    Queue taskQ, workerQ;
    init(&taskQ);
    init(&workerQ);

    sort(tasks, n);
    sort(workers, m);

    for (int i = 0; i < n; i++)
        enqueue(&taskQ, tasks[i]);
    for (int i = 0; i < m; i++)
        enqueue(&workerQ, workers[i]);

    while (!isEmpty(&taskQ) && !isEmpty(&workerQ)) {
        int task = dequeue(&taskQ);
        int worker = dequeue(&workerQ);

        if (worker >= task) {
            completed++;
        } else if (pills > 0 && (worker + strength) >= task) {
            pills--;
            completed++;
        } else {
            // worker too weak, skip this task
            // task remains uncompleted (you can requeue if needed)
        }
    }

    printf("Maximum tasks completed (using Queue): %d\n", completed);
    return 0;
}
