/*
 * P15. Implement the Prim's and Kruskal Algorithm using Greedy and analyze the algorithm.
 * Subject: Design and Analysis of Algorithms Lab (MCA-201)
 * Name: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem, Sec-B
 */

#include <iostream>
using namespace std;

// ========================
// PRIM'S ALGORITHM
// ========================
#define V_PRIM 5

int minKey(int key[], bool mstSet[])
{
    int min = 10000, min_index = -1;
    for (int v = 0; v < V_PRIM; v++)
    {
        if (!mstSet[v] && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST(int parent[], int graph[V_PRIM][V_PRIM])
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V_PRIM; i++)
    {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
    }
}

void primMST(int graph[V_PRIM][V_PRIM])
{
    int parent[V_PRIM];
    int key[V_PRIM];
    bool mstSet[V_PRIM];

    for (int i = 0; i < V_PRIM; i++)
    {
        key[i] = 10000;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V_PRIM - 1; count++)
    {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V_PRIM; v++)
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

// ========================
// KRUSKAL'S ALGORITHM
// ========================
struct Edge
{
    int src, dest, weight;
};

void sortEdges(Edge edges[], int E)
{
    for (int i = 0; i < E - 1; i++)
    {
        for (int j = i + 1; j < E; j++)
        {
            if (edges[i].weight > edges[j].weight)
            {
                Edge temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }
}

int findParent(int parent[], int i)
{
    if (parent[i] == i)
        return i;
    return findParent(parent, parent[i]);
}

void unionSetsKruskal(int parent[], int rank[], int x, int y)
{
    int rootX = findParent(parent, x);
    int rootY = findParent(parent, y);

    if (rank[rootX] < rank[rootY])
        parent[rootX] = rootY;
    else if (rank[rootX] > rank[rootY])
        parent[rootY] = rootX;
    else
    {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

void kruskalMST(Edge edges[], int V, int E)
{
    sortEdges(edges, E);

    int parent[V], rank[V];
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }

    Edge result[V];
    int e = 0;
    int i = 0;

    while (e < V - 1 && i < E)
    {
        Edge next_edge = edges[i++];
        int x = findParent(parent, next_edge.src);
        int y = findParent(parent, next_edge.dest);

        if (x != y)
        {
            result[e++] = next_edge;
            unionSetsKruskal(parent, rank, x, y);
        }
    }

    cout << "Edges in the constructed MST:\n";
    for (int j = 0; j < e; j++)
    {
        cout << result[j].src << " -- " << result[j].dest << " == " << result[j].weight << endl;
    }
}

int main()
{
    cout << "========================================" << endl;
    cout << "   PRIM'S ALGORITHM (GREEDY APPROACH)   " << endl;
    cout << "========================================" << endl;
    int graph[V_PRIM][V_PRIM] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    primMST(graph);

    cout << "\n========================================" << endl;
    cout << "  KRUSKAL'S ALGORITHM (GREEDY APPROACH) " << endl;
    cout << "========================================" << endl;
    int V = 4;
    int E = 5;
    Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    kruskalMST(edges, V, E);

    return 0;
}
