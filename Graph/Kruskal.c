#include <stdio.h>
#include <stdlib.h>

struct Edge
{
    int src, dst, weight;
};

struct Graph
{
    int V, E;
    struct Edge *edge;
};
struct Graph *createGraph(int V, int E)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge *)malloc(E * sizeof(struct Edge));
    return graph;
}

struct subset
{
    int parent;
    int rank;
};

int find(struct subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int compare(const void *a, const void *b)
{
    struct Edge *a1 = (struct Edge *)a;
    struct Edge *b1 = (struct Edge *)b;
    return a1->weight > b1->weight;
}

void KruskalMST(struct Graph *graph)
{
    int V = graph->V;
    struct Edge result[V]; // Store the result MST
    int e = 0;             // Index for result[]
    int i = 0;             // Index for sorted edges
    int totalWeight = 0;

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compare);

    struct subset *subsets = (struct subset *)malloc(V * sizeof(struct subset));

    for (int v = 0; v < V; v++)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < graph->E)
    {
        struct Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dst);

        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
            totalWeight += next_edge.weight;
        }
    }

    printf("Edges of MST:\n");
    for (int i = 0; i < e; i++)
        printf("%d -- %d == %d\n", result[i].src, result[i].dst, result[i].weight);

    printf("Total weight of MST: %d\n", totalWeight);

    free(subsets);
}

int main()
{
    int E = 5;
    int V = 4;
    struct Graph *graph = createGraph(V, E);

    graph->edge[0].src = 0;
    graph->edge[0].dst = 1;
    graph->edge[0].weight = 10;

    graph->edge[1].src = 0;
    graph->edge[1].dst = 2;
    graph->edge[1].weight = 6;

    graph->edge[2].src = 0;
    graph->edge[2].dst = 3;
    graph->edge[2].weight = 5;

    graph->edge[3].src = 1;
    graph->edge[3].dst = 3;
    graph->edge[3].weight = 15;

    graph->edge[4].src = 2;
    graph->edge[4].dst = 3;
    graph->edge[4].weight = 4;

    KruskalMST(graph);

    return 0;
}