/*After end term examination, Akshay wants to party with his friends. All his friends
are living as paying guest and it has been decided to first gather at Akshay’s house
and then move towards party location. The problem is that no one knows the exact
address of his house in the city. Akshay as a computer science wizard knows how to
apply his theory subjects in his real life and came up with an amazing idea to help
his friends. He draws a graph by looking in to location of his house and his friends’
location (as a node in the graph) on a map. He wishes to find out shortest distance
and path covering that distance from each of his friend’s location to his house and
then whatsapp them this path so that they can reach his house in minimum time.
Akshay has developed the program that implements Dijkstra’s algorithm but not
sure about correctness of results. Can you also implement the same algorithm and
verify the correctness of Akshay’s results? (Hint: Print shortest path and distance
from friends’ location to Akshay’s house)*/

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 100 
int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}
void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;
    printPath(parent, parent[j]);
    printf("%d ", j);
}
void printSolution(int dist[], int parent[], int n) {
    int src = 0; 
    printf("Vertex\t Distance\tPath\n");
    for (int i = 1; i < n; i++) {
        printf("%d -> %d\t %d\t\t%d ", src, i, dist[i], src);
        printPath(parent, i);
        printf("\n");
    }
}
void dijkstra(int graph[V][V], int src, int n) {
    int dist[V];
    bool sptSet[V];
    int parent[V];

    for (int i = 0; i < n; i++) {
        parent[src] = -1;
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < n; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, parent, n);
}
int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int graph[V][V];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    dijkstra(graph, 0, n); // Assuming Akshay's house is at vertex 0

    return 0;
}