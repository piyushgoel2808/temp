/*
 * P11. Implement and analyze the disjoint data structure algorithm.
 * Subject: Design and Analysis of Algorithms Lab (MCA-201)
 * Name: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem, Sec-B
 */

#include <iostream>
using namespace std;

class DisjointSet
{
    int *parent, *rank;
    int n;

public:
    DisjointSet(int n)
    {
        this->n = n;
        parent = new int[n + 1];
        rank = new int[n + 1];
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    ~DisjointSet()
    {
        delete[] parent;
        delete[] rank;
    }

    int find(int u)
    {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unionSets(int u, int v)
    {
        u = find(u);
        v = find(v);

        if (u == v)
            return;

        if (rank[u] > rank[v])
            parent[v] = u;
        else if (rank[u] < rank[v])
            parent[u] = v;
        else
        {
            parent[v] = u;
            rank[u]++;
        }
    }
};

int main()
{
    DisjointSet ds(5);
    ds.unionSets(1, 2);
    ds.unionSets(3, 4);
    ds.unionSets(2, 3);

    cout << "1 and 3 are in the same set? " << (ds.find(1) == ds.find(3)) << endl;

    return 0;
}
