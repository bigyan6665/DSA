// undirected,weighted graph
#include <stdio.h>
#include <stdlib.h>
// Structure to represent the graph as an adjacency matrix
struct Graph
{
    int numVertices;
    int **adjMatrix;
    int **wtmatrix; // stores weight of the edges
};

// Function to create a graph with a given number of vertices
void createGraph(struct Graph *var, int numVertices)
{
    // Graph *graph = (Graph *)malloc(sizeof(Graph));
    var->numVertices = numVertices;

    // Allocate memory for the adjacency matrixi.e 2D array
    var->adjMatrix = (int **)calloc(numVertices, sizeof(int *));
    for (int i = 0; i < numVertices; ++i)
    {
        var->adjMatrix[i] = (int *)calloc(numVertices, sizeof(int));
    }
    // Allocate memory for the weight matrixi.e 2D array
    var->wtmatrix = (int **)calloc(numVertices, sizeof(int *));
    for (int i = 0; i < numVertices; ++i)
    {
        var->wtmatrix[i] = (int *)calloc(numVertices, sizeof(int));
    }
}

// Function to add an edge to the graph
void addEdge(struct Graph *var, int src, int dest, int weight)
{
    // For an undirected graph, set both src to dest and dest to src
    var->wtmatrix[src][dest] = weight;
    var->wtmatrix[dest][src] = weight;
    var->adjMatrix[src][dest] = 1; // we are considering only one edge in between any pair of vertices
    var->adjMatrix[dest][src] = 1;
    //     var->adjMatrix[src][dest] += 1;//in this case,multiple edges can exist between any pair of vertices
    //     var->adjMatrix[dest][src] += 1;
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
    printf("Corresponding weight Matrix:\n");
    for (int i = 0; i < var->numVertices; ++i)
    {
        for (int j = 0; j < var->numVertices; ++j)
        {
            printf("%d ", var->wtmatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to free the memory allocated for the graph
// void destroyGraph(struct Graph *var)
// {
//     for (int i = 0; i < var->numVertices; ++i)
//         free(var->adjMatrix[i]);
//     free(var->adjMatrix);
//     free(var);
// }

int main()
{
    struct Graph obj;
    // Create a graph with 5 vertices
    createGraph(&obj, 5);
    // Add edges to the graph
    addEdge(&obj, 0, 1, 50);
    addEdge(&obj, 0, 4, 60);
    addEdge(&obj, 1, 2, 36);
    addEdge(&obj, 1, 3, 67);
    addEdge(&obj, 1, 4, 78);
    addEdge(&obj, 2, 3, 79);
    addEdge(&obj, 3, 4, 44);
    // Print the adjacency matrix
    printGraph(&obj);
    // Free the memory
    // destroyGraph(&obj);
    return 0;
}
