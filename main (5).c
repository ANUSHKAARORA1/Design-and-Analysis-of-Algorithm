/*Given a directed graph with two vertices ( source and destination). Design an
algorithm and implement it using a program to find the weight of the shortest path
from source to destination with exactly k edges on the path.*/

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
int shortestPathKEdges(struct Graph* graph, int src, int dest, int k) {
    int vertices = graph->vertices;
    int edges = graph->edges;
    int dp[vertices][vertices][k + 1];

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            for (int kk = 0; kk <= k; kk++) {
                dp[i][j][kk] = INT_MAX;
            }
        }
    }

    for (int i = 0; i < edges; i++) {
        int u = graph->edge[i].source;
        int v = graph->edge[i].destination;
        int weight = graph->edge[i].weight;
        dp[u][v][0] = weight;
    }

    for (int kk = 1; kk <= k; kk++) {
        for (int m = 0; m < vertices; m++) {
            for (int i = 0; i < vertices; i++) {
                for (int j = 0; j < vertices; j++) {
                    if (dp[i][m][kk - 1] != INT_MAX && dp[m][j][0] != INT_MAX) {
                        if (dp[i][m][kk - 1] + dp[m][j][0] < dp[i][j][kk]) {
                            dp[i][j][kk] = dp[i][m][kk - 1] + dp[m][j][0];
                        }
                    }
                }
            }
        }
    }

    return dp[src][dest][k];
}
int main() {
    int vertices, edges, src, dest, k;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &vertices, &edges);

    struct Graph* graph = createGraph(vertices, edges);

    printf("Enter the adjacency list representation of the graph (source destination weight):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &graph->edge[i].source, &graph->edge[i].destination, &graph->edge[i].weight);
    }

    printf("Enter the source vertex: ");
    scanf("%d", &src);

    printf("Enter the destination vertex: ");
    scanf("%d", &dest);

    printf("Enter the number of edges on the path: ");
    scanf("%d", &k);

    int shortestPathWeight = shortestPathKEdges(graph, src, dest, k);

    if (shortestPathWeight == INT_MAX) {
        printf("No path with exactly %d edges exists from source to destination.\n", k);
    } else {
        printf("Shortest path weight from source to destination with exactly %d edges: %d\n", k, shortestPathWeight);
    }

    return 0;
}