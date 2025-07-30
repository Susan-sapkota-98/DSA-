#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

int minKey(int key[], int mstSet[], int V)
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(int parent[], int graph[MAX][MAX], int V)
{
    int totalWeight = 0;
    printf("Edges of MST:\n");
    for (int i = 1; i < V; i++)
    {
        printf("%d -- %d == %d\n", parent[i], i, graph[i][parent[i]]);
        totalWeight += graph[i][parent[i]];
    }
    printf("Total weight of MST: %d\n", totalWeight);
}

void primMST(int graph[MAX][MAX], int V)
{
    int parent[V]; // To store MST
    int key[V];    // Weights
    int mstSet[V]; // Visited nodes

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = 0;

    key[0] = 0;     // Start from vertex 0
    parent[0] = -1; // First node is root

    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet, V);
        mstSet[u] = 1;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph, V);
}

int main()
{
    int V = 4;
    int graph[MAX][MAX] = {
        {0, 10, 6, 5},
        {10, 0, 0, 15},
        {6, 0, 0, 4},
        {5, 15, 4, 0}};

    primMST(graph, V);

    return 0;
}
