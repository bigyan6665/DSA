//undirected,unweighted graph
#include <stdio.h>
#include <stdlib.h>

// Structure to represent the graph as an adjacency matrix
struct Graph
{
    int numVertices;
    int **adjMatrix;
};

// Function to create a graph with a given number of vertices
void createGraph(struct Graph *var, int numVertices)
{
    // Graph *graph = (Graph *)malloc(sizeof(Graph));
    var->numVertices = numVertices;

    // Allocate memory for the adjacency matrixi.e 2D array
    var->adjMatrix = (int **)malloc(numVertices * sizeof(int *));
    for (int i = 0; i < numVertices; ++i)
    {
        var->adjMatrix[i] = (int *)calloc(numVertices, sizeof(int));
    }
}

// Function to add an edge to the graph
void addEdge(struct Graph *var, int src, int dest)
{
    // For an undirected graph, set both src to dest and dest to src
    var->adjMatrix[src][dest] = 1;
    var->adjMatrix[dest][src] = 1;
}

// Function to print the adjacency matrix of the graph
void printGraph(struct Graph *var)
{
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < var->numVertices; ++i)
    {
        for (int j = 0; j < var->numVertices; ++j)
        {
            printf("%d ", var->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to free the memory allocated for the graph
void destroyGraph(struct Graph *var)
{
    for (int i = 0; i < var->numVertices; ++i)
        free(var->adjMatrix[i]);
    free(var->adjMatrix);
    free(var);
}

int main()
{
    struct Graph obj;
    // Create a graph with 5 vertices
    createGraph(&obj, 5);

    // Add edges to the graph
    addEdge(&obj, 0, 1);
    addEdge(&obj, 0, 4);
    addEdge(&obj, 1, 2);
    addEdge(&obj, 1, 3);
    addEdge(&obj, 1, 4);
    addEdge(&obj, 2, 3);
    addEdge(&obj, 3, 4);

    // Print the adjacency matrix
    printGraph(&obj);

    // Free the memory
    destroyGraph(&obj);

    return 0;
}
