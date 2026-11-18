/*
 * P15 (Part 2). Implement Kruskal's Algorithm using Greedy approach.
 * Subject: Design and Analysis of Algorithms Lab (MCA-201)
 * Name: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem, Sec-B
 */

#include <iostream>
using namespace std;

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

int find(int parent[], int i)
{
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

void Union(int parent[], int rank[], int x, int y)
{
    int rootX = find(parent, x);
    int rootY = find(parent, y);

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
        int x = find(parent, next_edge.src);
        int y = find(parent, next_edge.dest);

        if (x != y)
        {
            result[e++] = next_edge;
            Union(parent, rank, x, y);
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
    int V = 4;
    int E = 5;
    Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    cout << "=== Kruskal's Minimum Spanning Tree ===" << endl;
    kruskalMST(edges, V, E);

    return 0;
}
