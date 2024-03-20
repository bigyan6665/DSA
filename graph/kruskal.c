#include <stdio.h>
#include <stdlib.h>
#define MAX 30
// Structure to represent edges
struct Edge
{
    int src, dest, weight;
};
// Structure to represent a graph
struct Graph
{
    int V, E;
    struct Edge *edge;
};
// Function prototypes
struct Graph *createGraph(int V, int E);
void printMST(struct Edge *result, int e);
void KruskalMST(struct Graph *graph);
int parent[MAX];
// Find set of an element i
int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}
// Perform union of two sets
void unionSet(int i, int j)
{
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}
// Create a graph with V vertices and E edges
struct Graph *createGraph(int V, int E)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;

    graph->edge = (struct Edge *)malloc(graph->E * sizeof(struct Edge));
    return graph;
}
// Compare function for qsort
int compare(const void *a, const void *b)
{
    struct Edge *a1 = (struct Edge *)a;
    struct Edge *b1 = (struct Edge *)b;
    return a1->weight > b1->weight;
}
// Function to print the MST
void printMST(struct Edge *result, int e)
{
    int minimumCost = 0;
    printf("Edges in MST:\n");
    for (int i = 0; i < e; ++i)
    {
        printf("%d - %d : %d\n", result[i].src, result[i].dest, result[i].weight);
        minimumCost += result[i].weight;
    }
    printf("Minimum Cost Spanning Tree: %d\n", minimumCost);
}
// Kruskal's algorithm
void KruskalMST(struct Graph *graph)
{
    int V = graph->V;
    struct Edge result[V];
    int e = 0; // An index variable, used for result[]
    int i = 0; // An index variable, used for sorted edges

    // Step 1: Sort all the edges in non-decreasing order of their weight
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compare);

    // Initialize parent array
    for (int v = 0; v < V; v++)
        parent[v] = v;

    // Number of edges to be taken is equal to V-1
    while (e < V - 1 && i < graph->E)
    {
        // Step 2: Pick the smallest edge. And increment the index for next iteration
        struct Edge next_edge = graph->edge[i++];

        int x = find(next_edge.src);
        int y = find(next_edge.dest);

        // If including this edge does't cause cycle, include it in result and union the sets
        if (x != y)
        {
            result[e++] = next_edge;
            unionSet(x, y);
        }
        // Else discard the next_edge
    }

    // Print the constructed MST
    printMST(result, e);
}

// Driver program
int main()
{
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    struct Graph *graph = createGraph(V, E);

    printf("Enter the edges with weights (source, destination, weight):\n");
    for (int i = 0; i < E; ++i)
    {
        scanf("%d %d %d", &graph->edge[i].src, &graph->edge[i].dest, &graph->edge[i].weight);
    }

    KruskalMST(graph);

    return 0;
}
