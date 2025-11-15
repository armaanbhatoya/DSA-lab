#include <stdio.h>

void dfs(int room, int visited[], int n, int rooms[][10], int sizes[]) {
    visited[room] = 1;

    for (int i = 0; i < sizes[room]; i++) {
        int key = rooms[room][i];
        if (!visited[key])
            dfs(key, visited, n, rooms, sizes);
    }
}

int main() {
    int n;
    printf("Enter number of rooms: ");
    scanf("%d", &n);

    int rooms[n][10];     // max 10 keys per room (you can change)
    int sizes[n];         // number of keys in each room

    for (int i = 0; i < n; i++) {
        printf("Enter number of keys in room %d: ", i);
        scanf("%d", &sizes[i]);

        printf("Enter the keys: ");
        for (int j = 0; j < sizes[i]; j++)
            scanf("%d", &rooms[i][j]);
    }

    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    dfs(0, visited, n, rooms, sizes);

    // Check if all rooms visited
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            printf("false\n");
            return 0;
        }
    }

    printf("true\n");
    return 0;
}
