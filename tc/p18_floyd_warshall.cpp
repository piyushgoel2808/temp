/*
 * P18. Implement Floyd-Warshall algorithm for a given graph.
 * Compatible with Turbo C++ 3.0
 * Subject: Design and Analysis of Algorithms Lab (MCA-201)
 * Name: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem, Sec-B
 */

#include <iostream.h>
#include <conio.h>

#define INF 10000

void floydWarshall(int graph[10][10], int V)
{
    int dist[10][10];
    int i, j, k;

    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            dist[i][j] = graph[i][j];
        }
    }

    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    cout << "Shortest distances between every pair of vertices:\n";
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int V = 4;
    int graph[10][10] = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };

    clrscr();

    floydWarshall(graph, V);

    getch();
    return 0;
}
