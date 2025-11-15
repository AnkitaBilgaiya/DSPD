#include <stdio.h>
#define MAX 30

int parent[MAX];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void union1(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int main() {
    int n, cost[MAX][MAX];
    int i, j, a = -1, b = -1, u, v;
    int mincost = 0, ne = 1;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    for (i = 1; i <= n; i++)
        parent[i] = i;

    printf("The edges of the Minimum Cost Spanning Tree:\n");

    while (ne < n) {
        int min = 999;

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        u = find(a);
        v = find(b);

        if (u != v) {
            printf("Edge %d: (%d - %d) = %d\n", ne++, a, b, min);
            mincost += min;
            union1(u, v);
        }

        cost[a][b] = cost[b][a] = 999;  
    }

    printf("Minimum cost = %d\n", mincost);

    return 0;
}
