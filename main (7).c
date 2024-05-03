/*Assume that a project of road construction to connect some cities is given to your
friend. Map of these cities and roads which will connect them (after construction) is
provided to him in the form of a graph. Certain amount of rupees is associated with
construction of each road. Your friend has to calculate the minimum budget
required for this project. The budget should be designed in such a way that the cost
of connecting the cities should be minimum and number of roads required to
connect all the cities should be minimum (if there are N cities then only N-1 roads
need to be constructed). He asks you for help. Now, you have to help your friend by
designing an algorithm which will find minimum cost required to connect these
cities. (use Prim's algorithm)*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100
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
void primMST(struct Graph* graph) {
    int vertices = graph->vertices;
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    bool mstSet[MAX_VERTICES];
    for (int i = 0; i < vertices; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < vertices - 1; count++) {
        int u = -1;
        for (int v = 0; v < vertices; v++) {
            if (!mstSet[v] && (u == -1 || key[v] < key[u]))
                u = v;
        }
        mstSet[u] = true;
        for (int v = 0; v < vertices; v++) {
            if (graph->edge[u * vertices + v].weight && !mstSet[v] &&
                graph->edge[u * vertices + v].weight < key[v]) {
                parent[v] = u;
                key[v] = graph->edge[u * vertices + v].weight;
            }
        }
    }
    int minCost = 0;
    for (int i = 1; i < vertices; i++) {
        minCost += graph->edge[parent[i] * vertices + i].weight;
    }
    printf("Minimum cost required to connect cities: %d\n", minCost);
}
int main() {
    int vertices, edges;
    printf("Enter the number of cities and roads: ");
    scanf("%d %d", &vertices, &edges);

    struct Graph* graph = createGraph(vertices, vertices * vertices);

    printf("Enter the adjacency matrix representation of the graph (0 for no connection):\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph->edge[i * vertices + j].weight);
            graph->edge[i * vertices + j].source = i;
            graph->edge[i * vertices + j].destination = j;
        }
    }

    primMST(graph);

    return 0;
}