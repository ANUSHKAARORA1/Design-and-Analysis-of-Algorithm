#include<stdio.h>

#define MAX 100

int graph[MAX][MAX], visited[MAX], vertices;

void initializeGraph() {
    int i, j;
    for (i = 0; i < MAX; i++) {
        visited[i] = 0;
        for (j = 0; j < MAX; j++)
            graph[i][j] = 0;
    }
}
void DFS(int vertex) {
    int i;
    visited[vertex] = 1;
    for (i = 0; i < vertices; i++) {
        if (graph[vertex][i] && !visited[i])
            DFS(i);
    }
}
int main() {
    int source, destination, i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < vertices; i++)
        for (j = 0; j < vertices; j++)
            scanf("%d", &graph[i][j]);
    printf("Enter the source vertex: ");
    scanf("%d", &source);
    printf("Enter the destination vertex: ");
    scanf("%d", &destination);

    initializeGraph();
    DFS(source);

    if (visited[destination])
        printf("Yes, Path Exists\n");
    else
        printf("No Such Path Exists\n");

    return 0;
}