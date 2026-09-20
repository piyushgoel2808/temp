/*
 * Program 18: Implementation of Floyd-Warshall Algorithm
 * Subject: Design and Analysis of Algorithms Lab (MCA-261 / MCA-201)
 * Name: Rudransh Singh Rawat | Roll No: 06411604425
 */

#include <stdio.h>

#define V 4
#define INF 99999

void printMatrix(int matrix[V][V]) {
    for (int i = 0; i < V; i++) {
        printf("  [ ");
        for (int j = 0; j < V; j++) {
            if (matrix[i][j] == INF)
                printf("%6s", "INF");
            else
                printf("%6d", matrix[i][j]);
        }
        printf(" ]\n");
    }
}

void floydWarshall(int graph[V][V]) {
    int dist[V][V];
    int i, j, k;

    // Initialize distance matrix same as input graph matrix
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Main 3 nested loops: k is intermediate vertex
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("\nFinal All-Pairs Shortest Distance Matrix:\n");
    printMatrix(dist);
}

int main() {
    /*
            10
       (0)------->(3)
        |         /|\
      5 |          |
        |          | 1
       \|/         |
       (1)------->(2)
             3
    */
    int graph[V][V] = {
        {0,   5,  INF, 10},
        {INF, 0,   3,  INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };

    printf("========================================\n");
    printf("     LAB 18: FLOYD-WARSHALL ALGORITHM   \n");
    printf("========================================\n");
    printf("Initial Adjacency Cost Matrix (Graph):\n");
    printMatrix(graph);

    floydWarshall(graph);

    printf("========================================\n");

    return 0;
}
