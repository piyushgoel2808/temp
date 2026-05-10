// Combine Dijkstra's shortest path and Warshall's transitive closure demos.
#include <stdio.h>

#define MAX 20
#define INF 999999

void runDijkstra(int n, int w[MAX][MAX]) {
    int source, i, count;
    int dist[MAX], visited[MAX] = {0};

    // Read the source vertex for shortest-path computation.
    printf("Enter source vertex: ");
    scanf("%d", &source);

    if (source < 0 || source >= n) {
        printf("Invalid source vertex.\n");
        return;
    }

    for (i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[source] = 0;

    // Grow the shortest-path tree one vertex at a time.
    for (count = 0; count < n - 1; count++) {
        int min = INF, u = -1;

        for (i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1) {
            break;
        }

        visited[u] = 1;

        // Relax all reachable neighbors from the chosen vertex.
        for (i = 0; i < n; i++) {
            if (!visited[i] && w[u][i] != INF && dist[u] + w[u][i] < dist[i]) {
                dist[i] = dist[u] + w[u][i];
            }
        }
    }

    printf("Shortest distance from vertex %d:\n", source);
    for (i = 0; i < n; i++) {
        if (dist[i] == INF) {
            printf("to %d = Not reachable\n", i);
        } else {
            printf("to %d = %d\n", i, dist[i]);
        }
    }
}

void runWarshall(int n, int w[MAX][MAX]) {
    int i, j, k;
    int reach[MAX][MAX];

    // Initialize reachability from the weighted adjacency matrix.
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j || w[i][j] != INF) {
                reach[i][j] = 1;
            } else {
                reach[i][j] = 0;
            }
        }
    }

    for (k = 0; k < n; k++) {
        // Allow each vertex to act as an intermediate path node.
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }

    printf("Warshall Transitive Closure Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", reach[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, i, j, choice;
    int w[MAX][MAX];
    int input;

    // Read the graph size and confirm it fits the fixed matrix.
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of vertices.\n");
        return 0;
    }

    // Convert 0 entries into INF so missing edges are easy to detect.
    printf("Enter weighted adjacency matrix (enter 0 where no edge exists):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &input);
            if (i == j) {
                w[i][j] = 0;
            } else if (input == 0) {
                w[i][j] = INF;
            } else {
                w[i][j] = input;
            }
        }
    }

    // Let the user choose which graph algorithm to run.
    printf("\n1. Dijkstra's Algorithm\n2. Warshall's Algorithm\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        runDijkstra(n, w);
    } else if (choice == 2) {
        runWarshall(n, w);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
