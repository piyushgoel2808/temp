// Perform depth-first search recursively using an adjacency matrix.
#include <stdio.h>

#define MAX 20

void dfs(int v, int n, int adj[MAX][MAX], int visited[MAX]) {
    int i;
    visited[v] = 1;
    // Visit the current vertex before exploring deeper neighbors.
    printf("%d ", v);

    for (i = 0; i < n; i++) {
        if (adj[v][i] != 0 && !visited[i]) {
            dfs(i, n, adj, visited);
        }
    }
}

int main() {
    int n, i, j, start;
    int adj[MAX][MAX];
    int visited[MAX] = {0};

    // Read the graph size first.
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of vertices.\n");
        return 0;
    }

    // Load the adjacency matrix used by the recursive DFS.
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Choose the vertex where traversal will begin.
    printf("Enter start vertex: ");
    scanf("%d", &start);

    if (start < 0 || start >= n) {
        printf("Invalid start vertex.\n");
        return 0;
    }

    // Start the recursive traversal from the selected vertex.
    printf("DFS Traversal: ");
    dfs(start, n, adj, visited);
    printf("\n");

    return 0;
}
