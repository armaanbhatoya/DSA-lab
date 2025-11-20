//  Problem 4: Key
//  There are n rooms labeled from 0 to n−1 and all the rooms are locked except for room 0. Your goal is to
//  visit all the rooms. However, you cannot enter a locked room without having its key.
//  When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting
//  which room it unlocks, and you can take all of them with you to unlock the other rooms.
//  Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true
//  if you can visit all the rooms, or false otherwise.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void dfs(int room, bool visited[], int **rooms, int roomsColSize[]) {
    visited[room] = true;

    for (int i = 0; i < roomsColSize[room]; i++) {
        int next = rooms[room][i];
        if (!visited[next]) {
            dfs(next, visited, rooms, roomsColSize);
        }
    }
}

bool canVisitAllRooms(int **rooms, int roomsSize, int roomsColSize[]) {
    bool visited[roomsSize];

    for (int i = 0; i < roomsSize; i++)
        visited[i] = false;

    dfs(0, visited, rooms, roomsColSize);

    for (int i = 0; i < roomsSize; i++)
        if (!visited[i])
            return false;

    return true;
}

int main() {
    int n;
    printf("Enter number of rooms: ");
    scanf("%d", &n);

    // Allocate memory
    int **rooms = (int **)malloc(n * sizeof(int *));
    int *roomsColSize = (int *)malloc(n * sizeof(int));

    // Input keys for each room
    for (int i = 0; i < n; i++) {
        printf("Enter number of keys in room %d: ", i);
        scanf("%d", &roomsColSize[i]);

        rooms[i] = (int *)malloc(roomsColSize[i] * sizeof(int));

        printf("Enter the keys (room numbers) in room %d: ", i);
        for (int j = 0; j < roomsColSize[i]; j++) {
            scanf("%d", &rooms[i][j]);
        }
    }

    // Check if all rooms can be visited
    if (canVisitAllRooms(rooms, n, roomsColSize))
        printf("True\n");
    else
        printf("False\n");

    // Free memory
    for (int i = 0; i < n; i++)
        free(rooms[i]);
    free(rooms);
    free(roomsColSize);

    return 0;
}
