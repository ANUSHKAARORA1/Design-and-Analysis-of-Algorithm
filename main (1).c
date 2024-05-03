//Given a graph, design an algorithm and implement it using a program to find if a graph is
//bipartite or not. (Hint: use BFS)

#include <stdio.h>
#include <stdbool.h>

#define MAX 100
int graph[MAX][MAX], colors[MAX], vertices;
bool isBipartite(int source) {
    int queue[MAX], front = -1, rear = -1, current, i;
    colors[source] = 1;
    queue[++rear] = source;

    while (front != rear) {
        current = queue[++front];
        for (i = 0; i < vertices; i++) {
            if (graph[current][i]) {
                if (colors[i] == -1) {
                    colors[i] = 1 - colors[current];
                    queue[++rear] = i;
                } else if (colors[i] == colors[current]) {
                    return false;
                }
            }
        }
    }
    return true;
}
int main() {
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < vertices; i++)
        for (j = 0; j < vertices; j++)
            scanf("%d", &graph[i][j]);

    for (i = 0; i < vertices; i++)
        colors[i] = -1;

    if (isBipartite(0))
        printf("Yes Bipartite\n");
    else
        printf("Not Bipartite\n");

    return 0;
}