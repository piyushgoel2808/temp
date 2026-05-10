#include <stdio.h>

#define MAX 20

int main() {
    int n, i, j, start;
    int adj[MAX][MAX];
    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of vertices.\n");
        return 0;
    }

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter start vertex: ");
    scanf("%d", &start);

    if (start < 0 || start >= n) {
        printf("Invalid start vertex.\n");
        return 0;
    }

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal: ");
    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        for (i = 0; i < n; i++) {
            if (adj[v][i] != 0 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");

    return 0;
}
