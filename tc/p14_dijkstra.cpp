/*
 * P14. Implement the Dijkstra Algorithm using Greedy and analyze the algorithm.
 * Compatible with Turbo C++ 3.0
 * Subject: Design and Analysis of Algorithms Lab (MCA-201)
 * Name: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem, Sec-B
 */

#include <iostream.h>
#include <conio.h>

#define V 9
#define INF 10000

int minDistance(int dist[], int sptSet[])
{
    int min = INF, min_index = -1;
    int v;

    for (v = 0; v < V; v++)
    {
        if (!sptSet[v] && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    int sptSet[V];
    int i, count, u, v;

    for (i = 0; i < V; i++)
    {
        dist[i] = INF;
        sptSet[i] = 0;
    }

    dist[src] = 0;

    for (count = 0; count < V - 1; count++)
    {
        u = minDistance(dist, sptSet);
        if (u == -1)
            break;

        sptSet[u] = 1;

        for (v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Vertex \t Distance from Source\n";
    for (i = 0; i < V; i++)
    {
        cout << i << " \t\t " << dist[i] << "\n";
    }
}

int main()
{
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    clrscr();

    dijkstra(graph, 0);

    getch();
    return 0;
}
