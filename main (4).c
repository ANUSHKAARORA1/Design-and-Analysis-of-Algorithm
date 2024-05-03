/*Design an algorithm and implement it using a program to solve previous question's
problem using Bellman- Ford's shortest path algorithm.*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100
#define MAX_EDGES 100
struct Edge {
    int source, destination, weight;
};

struct Graph {
    int vertices, edges;
    struct Edge* edge;
};
struct Graph* createGraph(int vertices, int edges) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->edges = edges;
    graph->edge = (struct Edge*)malloc(edges * sizeof(struct Edge));
    return graph;
}
void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;
    printPath(parent, parent[j]);
    printf("%d ", j);
}
void printSolution(int dist[], int parent[], int src, int n) {
    printf("Vertex\t Distance\tPath\n");
    for (int i = 0; i < n; i++) {
        if (i == src)
            continue;
        printf("%d -> %d\t %d\t\t%d ", i, src, dist[i], i);
        printPath(parent, i);
        printf("\n");
    }
}
void BellmanFord(struct Graph* graph, int src) {
    int vertices = graph->vertices;
    int edges = graph->edges;
    int dist[MAX_VERTICES];
    int parent[MAX_VERTICES];

    for (int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }
    dist[src] = 0;

    for (int i = 1; i <= vertices - 1; i++) {
        for (int j = 0; j < edges; j++) {
            int u = graph->edge[j].source;
            int v = graph->edge[j].destination;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
            }
        }
    }

    // Check for negative weight cycles
    for (int j = 0; j < edges; j++) {
        int u = graph->edge[j].source;
        int v = graph->edge[j].destination;
        int weight = graph->edge[j].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }
    printSolution(dist, parent, src, vertices);
}
int main() {
    int vertices, edges, src;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &vertices, &edges);

    struct Graph* graph = createGraph(vertices, edges);

    printf("Enter the adjacency list representation of the graph:\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &graph->edge[i].source, &graph->edge[i].destination, &graph->edge[i].weight);
    }

    printf("Enter the source vertex: ");
    scanf("%d", &src);

    BellmanFord(graph, src);

    return 0;
}