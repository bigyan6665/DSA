#include <stdio.h>
#include <stdlib.h>

// Structure to represent the graph as an adjacency matrix
typedef struct Graph
{
    int numVertices;
    int **adjMatrix;
} Graph;

// Function to create a graph with a given number of vertices
Graph *createGraph(int numVertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = numVertices;

    // Allocate memory for the adjacency matrix
    graph->adjMatrix = (int **)malloc(numVertices * sizeof(int *));
    for (int i = 0; i < numVertices; ++i)
        graph->adjMatrix[i] = (int *)calloc(numVertices, sizeof(int));

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph *graph, int src, int dest)
{
    // For an undirected graph, set both src to dest and dest to src
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

// Function to print the adjacency matrix of the graph
void printGraph(Graph *graph)
{
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->numVertices; ++i)
    {
        for (int j = 0; j < graph->numVertices; ++j)
        {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to free the memory allocated for the graph
void destroyGraph(Graph *graph)
{
    for (int i = 0; i < graph->numVertices; ++i)
        free(graph->adjMatrix[i]);
    free(graph->adjMatrix);
    free(graph);
}

int main()
{
    // Create a graph with 5 vertices
    Graph *graph = createGraph(5);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Print the adjacency matrix
    printGraph(graph);

    // Free the memory
    destroyGraph(graph);

    return 0;
}
