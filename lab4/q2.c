// find makimum area covered by 1 in matrix containg 1s and 0s only
#include <stdio.h>
#include <stdlib.h>

/* Globals to keep code simple for explanation */
int ROWS, COLS;
int **matrix;
int **visited;

/* 8 directions (row offset, col offset):
   diagonals included. For 4-directional, remove diagonals. */
int drow[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
int dcol[8] = {-1,  0,  1, -1, 1, -1, 0, 1};

/* DFS: explore from (r,c) and return area (count of connected 1s) */
int dfs(int r, int c) {
    /* mark current cell visited immediately */
    visited[r][c] = 1;
    int area = 1;              // count this cell

    /* try all 8 neighbors */
    for (int k = 0; k < 8; k++) {
        int nr = r + drow[k];
        int nc = c + dcol[k];

        /* check bounds, value 1, and not visited */
        if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && matrix[nr][nc] == 1 && !visited[nr][nc]) {
            area += dfs(nr, nc);   // go deeper
        }
    }
    return area;
}

int main() {
    printf("Enter number of rows and columns: ");
    if (scanf("%d %d", &ROWS, &COLS) != 2) {
        printf("Invalid input.\n");
        return 1;
    }

    /* allocate matrix and visited arrays dynamically */
    matrix = (int **)malloc(ROWS * sizeof(int *));
    visited = (int **)malloc(ROWS * sizeof(int *));
    for (int i = 0; i < ROWS; i++) {
        matrix[i] = (int *)malloc(COLS * sizeof(int));
        visited[i] = (int *)malloc(COLS * sizeof(int));
    }

    printf("Enter the matrix (each row on a new line, 0 or 1):\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            scanf("%d", &matrix[i][j]);
            visited[i][j] = 0;   // initialize visited
        }
    }

    printf("\nInput matrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int maxArea = 0;

    /* traverse the matrix, launch DFS from every unvisited 1 */
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] == 1 && !visited[i][j]) {
                int area = dfs(i, j);
                if (area > maxArea) maxArea = area;
            }
        }
    }

    printf("\nLargest connected group of 1s  = %d\n", maxArea);

    /* free memory */
    for (int i = 0; i < ROWS; i++) {
        free(matrix[i]);
        free(visited[i]);
    }
    free(matrix);
    free(visited);

    return 0;
}
