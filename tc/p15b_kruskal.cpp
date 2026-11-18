/*
 * P15 (Part 2). Kruskal's Algorithm (Turbo C++ Compatible)
 * Name: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem, Sec-B
 */

#include <iostream.h>
#include <conio.h>

struct Edge
{
    int src, dest, weight;
};

void sortEdges(Edge edges[], int E)
{
    int i, j;
    Edge temp;
    for (i = 0; i < E - 1; i++)
    {
        for (j = i + 1; j < E; j++)
        {
            if (edges[i].weight > edges[j].weight)
            {
                temp = edges[i];
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
    int parent[10], rank[10];
    Edge result[10];
    Edge next_edge;
    int e = 0, i = 0, j, x, y;

    sortEdges(edges, E);

    for (j = 0; j < V; j++)
    {
        parent[j] = j;
        rank[j] = 0;
    }

    while (e < V - 1 && i < E)
    {
        next_edge = edges[i++];
        x = findParent(parent, next_edge.src);
        y = findParent(parent, next_edge.dest);

        if (x != y)
        {
            result[e++] = next_edge;
            unionSetsKruskal(parent, rank, x, y);
        }
    }

    cout << "Edges in the constructed MST:\n";
    for (j = 0; j < e; j++)
    {
        cout << result[j].src << " -- " << result[j].dest << " == " << result[j].weight << "\n";
    }
}

int main()
{
    int V = 4;
    int E = 5;
    Edge edges[5];

    edges[0].src = 0; edges[0].dest = 1; edges[0].weight = 10;
    edges[1].src = 0; edges[1].dest = 2; edges[1].weight = 6;
    edges[2].src = 0; edges[2].dest = 3; edges[2].weight = 5;
    edges[3].src = 1; edges[3].dest = 3; edges[3].weight = 15;
    edges[4].src = 2; edges[4].dest = 3; edges[4].weight = 4;

    clrscr();

    cout << "=== Kruskal's Minimum Spanning Tree ===\n";
    kruskalMST(edges, V, E);

    getch();
    return 0;
}
