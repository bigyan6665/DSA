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
void printMST(struct edge *result, int e)
{
    int minimumCost = 0;
    printf("Edges in MST:\n");
    for (int i = 0; i < e; ++i)
    {
        printf("%d - %d : %d\n", result[i].src, result[i].dest, result[i].wt);
        minimumCost += result[i].wt;
    }
    printf("Minimum Cost Spanning Tree: %d\n", minimumCost);
}
void swapedge(struct edge *e1, struct edge *e2)
{
    int temp;
    temp = e1->dest;
    e1->dest = e2->dest;
    e2->dest = temp;

    temp = e1->src;
    e1->src = e2->src;
    e2->src = temp;

    temp = e1->wt;
    e1->wt = e2->wt;
    e2->wt = temp;
}
void printedge(struct edge *e1, int e)
{
    printf("\nsrc\tdest\tweight\n");
    for (int i = 0; i < e; ++i)
    {
        printf("\n%d\t%d\t%d\n", e1[i].src, e1[i].dest, e1[i].wt);
    }
}
void MSTKRUSKALS(struct graph *g)
{
    int V = g->v;
    struct edge mst[V];
    int e = 0; // An index variable, used for result[]
    int i = 0; // An index variable, used for sorted edges

    for (int i = 0; i < g->e - 1; i++) // bubble sort in ascending order of their weights
    {
        for (int j = 0; j < g->e - i - 1; j++)
        {
            if (g->EDGE[j].wt > g->EDGE[i].wt)
            {
                swapedge(&g->EDGE[j], &g->EDGE[j + 1]);
            }
        }
    }
    // printedge(g->EDGE, g->e);
    for (int v = 0; v < V; v++)
        parent[v] = v;
    while (e < V - 1 && i < g->e)
    {
        struct edge next_edge = g->EDGE[i++];
        int x = find(next_edge.src);
        int y = find(next_edge.dest);
        if (x != y)
        {
            mst[e++] = next_edge;
            unionSet(x, y);
        }
    }
    printMST(mst, e);
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
        fflush(stdin);
        scanf("%d %d", &g->EDGE[i].src, &g->EDGE[i].dest);
        fflush(stdin);
        scanf("%d", &g->EDGE[i].wt);
    }
    MSTKRUSKALS(g);
    return 0;
}