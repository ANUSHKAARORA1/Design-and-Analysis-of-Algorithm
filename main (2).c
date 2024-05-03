/*Given a directed graph, design an algorithm and implement it using a program to find whether
cycle exists in the graph or not.*/

#include<stdio.h>
#include<stdbool.h>
#define MAX 100
int graph[MAX][MAX], visited[MAX], stack[MAX], vertices;
bool cycle;
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
    stack[vertex] = 1;
    for (i = 0; i < vertices; i++) {
        if (graph[vertex][i]) {
            if (!visited[i]) {
                DFS(i);
            } else if (stack[i]) {
                cycle = true;
                return;
            }
        }
    }
    stack[vertex] = 0;
}
bool hasCycle() {
    int i;
    for (i = 0; i < vertices; i++) {
        if (!visited[i]) {
            DFS(i);
            if (cycle)
                return true;
        }
    }
    return false;
}
int main() {
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < vertices; i++)
        for (j = 0; j < vertices; j++)
            scanf("%d", &graph[i][j]);

    initializeGraph();
    cycle = false;

    if (hasCycle())
        printf("Yes Cycle Exists\n");
    else
        printf("No Cycle Exists\n");

    return 0;
}