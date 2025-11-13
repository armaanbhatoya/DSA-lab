// Problem 2: Fuel Station
 
//  A car travels from a starting position to a destination which is target miles east of the starting position.
//  There are gas stations along the way. The gas stations are represented as an array stations where stations[i] =
//  positioni,fueli indicates that the ith gas station is positioni miles east of the starting position and has fueli
//  liters of gas.
//  The car starts with an infinite tank of gas, which initially has startFuel liters of fuel in it. It uses one liter
//  of gas per one mile that it drives. When the car reaches a gas station, it may stop and refuel, transferring all
//  the gas from the station into the car.
//  Return the minimum number of refueling stops the car must make in order to reach its destination. If it
//  cannot reach the destination, return −1.
//  Note that if the car reaches a gas station with 0 fuel left, the car can still refuel there. If the car reaches the
//  destination with 0 fuel left, it is still considered to have arrived.
  
 
//  Example 1: Input: target = 1, startFuel = 1, stations = []
//  Output: 0
//  We can reach the target without refueling.
//  Example 2: Input: target = 100, startFuel = 1, stations = [[10,100]]
//  Output:-1
//  Explanation: We can not reach the target (or even the first gas station).
//  Example 3: Input: target = 100, startFuel = 10, stations = [[10,60],[20,30],[30,30],[60,40]]



// explain me the approach to solve this problem and then provide c code

// Approach

// This is a classic greedy problem solved with a max-heap (priority queue):

// Keep track of how far the car can currently go with the fuel you have (reach).

// Process gas stations in increasing order of position. For every station whose position is <= reach, push its fuel amount into a max-heap (these are stations you could stop at before running out).

// If reach is still less than the target, and there are no stations in the heap to use, you cannot proceed ⇒ return -1.

// Otherwise, pop the largest fuel from the heap (refuel at the station that gives the most fuel), add it to reach, increment stops, and continue.

// Repeat until reach >= target. The number of pops is the minimum number of refuels because you always choose the largest available fuel when needed — a greedy choice that minimizes number of stops.

// Time complexity: sorting (if needed) O(n log n) + heap operations O(n log n) overall.
// Space complexity: O(n) for the heap.

#include <stdio.h>
#include <stdlib.h>

#define MAX 10000  

int heap[MAX];
int heapSize = 0;

// ---------------- MAX HEAP FUNCTIONS ------------------

void push(int x) {
    heap[++heapSize] = x;

    int i = heapSize;
    while (i > 1 && heap[i/2] < heap[i]) {
        int temp = heap[i/2];
        heap[i/2] = heap[i];
        heap[i] = temp;
        i = i/2;
    }
}

int pop() {
    if (heapSize == 0) return 0;

    int max = heap[1];
    heap[1] = heap[heapSize--];

    int i = 1;
    while (1) {
        int left = 2*i;
        int right = left + 1;
        int largest = i;

        if (left <= heapSize && heap[left] > heap[largest])
            largest = left;

        if (right <= heapSize && heap[right] > heap[largest])
            largest = right;

        if (largest == i) break;

        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;

        i = largest;
    }

    return max;
}

// ---------------- MAIN LOGIC FUNCTION ------------------

int minRefuelStops(int target, int startFuel, int pos[], int fuel[], int n) {

    int reach = startFuel;
    int stops = 0;
    int i = 0;

    while (reach < target) {

        while (i < n && pos[i] <= reach) {
            push(fuel[i]);
            i++;
        }

        if (heapSize == 0)
            return -1;

        reach += pop();
        stops++;
    }
    return stops;
}

// -------------------------- MAIN -------------------------

int main() {

    // stations = [[10,60],[20,30],[30,30],[60,40]]
    int stations[4][2] = {
        {10, 60},
        {20, 30},
        {30, 30},
        {60, 40}
    };

    int pos[4], fuel[4];

    for (int i = 0; i < 4; i++) {
        pos[i] = stations[i][0];
        fuel[i] = stations[i][1];
    }

    int ans = minRefuelStops(100, 10, pos, fuel, 4);

    printf("Min stops = %d\n", ans);    

    return 0;
}
