
// Problem 2: Star Graph

//  There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where
//  there is one center node and exactly n −1 edges that connect the center node with every other node.
//  You are given a 2D integer array edges where each edges[i] = [ui,vi] indicates that there is an edge between
//  the nodes ui and vi. Return the center of the given star graph
 
#include <stdio.h>

int findCenter(int edges[][2], int n) {
    int a = edges[0][0];
    int b = edges[0][1];
    int c = edges[1][0];
    int d = edges[1][1];

    
    if (a == c || a == d)
        return a;
    return b;
}

int main() {
    int n;
    printf("Enter number of edges: ");
    scanf("%d", &n);

    int edges[n][2];

    printf("Enter edges (u v):\n");
    for (int i = 0; i < n; i++)
        scanf("%d %d", &edges[i][0], &edges[i][1]);

    int center = findCenter(edges, n);
    printf("Center of the star graph = %d\n", center);

    return 0;
}
