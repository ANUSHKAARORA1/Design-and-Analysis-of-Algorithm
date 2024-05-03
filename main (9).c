/*Assume that same road construction project is given to another person. The amount he will earn
from this project is directly proportional to the budget of the project. This person is greedy, so he
decided to maximize the budget by constructing those roads who have highest construction cost.
Design an algorithm and implement it using a program to find the maximum budget required for
the project.*/

#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge in the graph
struct Edge {
    int source, destination, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Function to find set of an element i
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Function to perform union of two sets
void unionSet(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare function used for sorting edges
int compare(const void* a, const void* b) {
    struct Edge* edge1 = (struct Edge*)a;
    struct Edge* edge2 = (struct Edge*)b;
    return edge2->weight - edge1->weight;
}

// Function to find maximum spanning tree using Kruskal's algorithm
int maxSpanningWeight(struct Edge* edges, int V, int E) {
    int maxWeight = 0;
    int i = 0;

    // Sort all edges in non-increasing order of their weight
    qsort(edges, E, sizeof(edges[0]), compare);

    // Allocate memory for creating V subsets
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));

    // Create V subsets with single elements
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Iterate through sorted edges
    while (i < E) {
        struct Edge nextEdge = edges[i++];

        int x = find(subsets, nextEdge.source);
        int y = find(subsets, nextEdge.destination);

        // If adding the current edge to the maximum spanning tree does not create a cycle, add it to the tree
        if (x != y) {
            maxWeight += nextEdge.weight;
            unionSet(subsets, x, y);
        }
    }

    free(subsets);

    return maxWeight;
}

int main() {
    int V, E;
    printf("Enter the number of cities and roads: ");
    scanf("%d %d", &V, &E);

    struct Edge* edges = (struct Edge*)malloc(E * sizeof(struct Edge));

    printf("Enter the source, destination, and cost of each road:\n");
    for (int i = 0; i < E; ++i)
        scanf("%d %d %d", &edges[i].source, &edges[i].destination, &edges[i].weight);

    int maxBudget = maxSpanningWeight(edges, V, E);

    printf("Maximum budget required for the project: %d\n", maxBudget);

    free(edges);

    return 0;
}