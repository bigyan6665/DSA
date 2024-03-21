#include <stdio.h>
#include <stdlib.h>
#define MAX 30

int parent[MAX];

struct edge
{
    int src, dest;
    int wt;
};

struct graph
{
    int v, e;
    struct edge *EDGE;
};

struct graph *creategraph(int V, int E)
{
    struct graph *g = (struct graph *)calloc(1, sizeof(struct graph));
    g->v = V;
    g->e = E;
    g->EDGE = (struct edge *)calloc(g->e, sizeof(struct edge));
    return g;
}

int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int i, int j)
{
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void printMST(struct graph *mst, int E)
{
    int minimumCost = 0;
    printf("Edges in MST:\n");
    for (int i = 0; i < E; ++i)
    {
        printf("%d - %d : %d\n", mst->EDGE[i].src, mst->EDGE[i].dest, mst->EDGE[i].wt);
        minimumCost += mst->EDGE[i].wt;
    }
    printf("Minimum Cost Spanning Tree: %d\n", minimumCost);
}

void MSTKRUSKALS(struct graph *g)
{
    int V = g->v;
    struct graph *mst = creategraph(V, V - 1);
    int E = 0; // An index variable, used for mst->EDGE[]
    for (int j = 0; j < g->e - 1; j++)
    {
        struct edge smallest;
        smallest.wt = 10000;
        for (int i = j; i < g->e - 1; i++)
        {
            if (smallest.wt < g->EDGE[i].wt)
            {
                smallest = *g->EDGE;
            }
        }

        // Initialize parent array for disjoint set
        for (int v = 0; v < V; v++)
            parent[v] = v;

        // Apply Kruskal's algorithm
        int i = 0; // An index variable, used for sorted edges
        while (E < V - 1 && i < g->e)
        {
            struct edge next_edge = g->EDGE[i++];
            int x = find(next_edge.src);
            int y = find(next_edge.dest);
            if (x != y)
            {
                mst->EDGE[E++] = next_edge;
                unionSet(x, y);
            }
        }
    }
    printMST(mst, V - 1);
    free(mst->EDGE);
    free(mst);
}

int main()
{
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);
    struct graph *g = creategraph(V, E);
    printf("Enter the edges with weights (source, destination, weight):\n");
    for (int i = 0; i < E; ++i)
    {
        scanf("%d %d %d", &g->EDGE[i].src, &g->EDGE[i].dest, &g->EDGE[i].wt);
    }
    MSTKRUSKALS(g);
    free(g->EDGE);
    free(g);
    return 0;
}
