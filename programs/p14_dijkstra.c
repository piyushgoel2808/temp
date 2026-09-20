/*
 * Program 14: Implementation of Dijkstra's Shortest Path Algorithm
 * Subject: Design and Analysis of Algorithms Lab (MCA-261 / MCA-201)
 * Name: Rudransh Singh Rawat | Roll No: 06411604425
 */

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 6

// Function to find vertex with minimum distance value
int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print path from source to j using parent array
void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        printf("%d", j);
        return;
    }
    printPath(parent, parent[j]);
    printf(" -> %d", j);
}

void printSolution(int dist[], int parent[], int src) {
    printf("Source Vertex: %d\n", src);
    printf("Vertex | Shortest Distance | Path\n");
    printf("------------------------------------------\n");
    for (int i = 0; i < V; i++) {
        printf("  %d    |        %2d         | ", i, dist[i]);
        printPath(parent, i);
        printf("\n");
    }
    printf("------------------------------------------\n");
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool sptSet[V];
    int parent[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        if (u == -1) break;
        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, parent, src);
}

int main() {
    // 6-vertex weighted graph adjacency matrix
    int graph[V][V] = {
        {0, 4, 2, 0, 0, 0},
        {4, 0, 1, 5, 0, 0},
        {2, 1, 0, 8, 10, 0},
        {0, 5, 8, 0, 2, 6},
        {0, 0, 10, 2, 0, 3},
        {0, 0, 0, 6, 3, 0}
    };

    printf("========================================\n");
    printf("      LAB 14: DIJKSTRA'S ALGORITHM      \n");
    printf("========================================\n");

    dijkstra(graph, 0);

    printf("========================================\n");

    return 0;
}
