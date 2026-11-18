/*
 * P15 (Part 1). Prim's Algorithm (Turbo C++ Compatible)
 * Name: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem, Sec-B
 */

#include <iostream.h>
#include <conio.h>

#define V 5

int minKey(int key[], int mstSet[])
{
    int min = 10000, min_index = -1;
    int v;
    for (v = 0; v < V; v++)
    {
        if (!mstSet[v] && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST(int parent[], int graph[V][V])
{
    int i;
    cout << "Edge \tWeight\n";
    for (i = 1; i < V; i++)
    {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
    }
}

void primMST(int graph[V][V])
{
    int parent[V];
    int key[V];
    int mstSet[V];
    int i, count, u, v;

    for (i = 0; i < V; i++)
    {
        key[i] = 10000;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (count = 0; count < V - 1; count++)
    {
        u = minKey(key, mstSet);
        mstSet[u] = 1;

        for (v = 0; v < V; v++)
        {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main()
{
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    clrscr();

    cout << "=== Prim's Minimum Spanning Tree ===\n";
    primMST(graph);

    getch();
    return 0;
}
