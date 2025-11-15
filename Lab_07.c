#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int n;

void BFS(int start) {
    int i;
    int front = -1, rear = -1;

    for (i = 1; i <= n; i++)
        visited[i] = 0;

    queue[++rear] = start;
    visited[start] = 1;

    while (front != rear) {
        int v = queue[++front];
        printf("%d ", v);

        for (i = 1; i <= n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void DFS(int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for (i = 1; i <= n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

int main() {
    int i, j, s, d, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter edges (s d). Enter 0 0 to stop:\n");
    while (1) {
        scanf("%d %d", &s, &d);
        if (s == 0 && d == 0)
            break;

        adj[s][d] = 1;
        adj[d][s] = 1;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    BFS(start);

    for (i = 1; i <= n; i++)
        visited[i] = 0;

    DFS(start);

    return 0;
}
