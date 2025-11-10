#include <stdio.h>

#define N 9
int adj[10][10] = {
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,1,0,0,0,0,0},  
    {0,1,0,1,0,1,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0},  
    {0,1,0,0,0,1,0,1,0,0},  
    {0,0,1,0,1,0,1,0,1,0},  
    {0,0,0,0,0,1,0,0,0,0},  
    {0,0,0,0,1,0,0,1,0,0}, 
    {0,0,0,0,0,1,0,1,0,1},  
    {0,0,0,0,0,0,0,0,1,0}   
};

void BFS(int start) {
    int visited[10] = {0}, queue[10], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;
    printf("BFS Order: ");
    while(front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        for(int i = 1; i <= N; i++) {
            if(adj[node][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

void DFS(int node, int visited[]) {
    printf("%d ", node);
    visited[node] = 1;
    for(int i = 1; i <= N; i++) {
        if(adj[node][i] && !visited[i])
            DFS(i, visited);
    }
}

int main() {
    int visited[10] = {0};
    printf("Start Node: 1\n");
    BFS(1);
    printf("DFS Order: ");
    DFS(1, visited);
    printf("\n");
    return 0;
}