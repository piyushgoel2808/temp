#include <stdio.h>

#define MAX 20
#define INF 999999

int main() {
    int n, i, j, count;
    int graph[MAX][MAX];
    int selected[MAX] = {0};
    int edgeCount = 0;
    int totalCost = 0;
    int input;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of vertices.\n");
        return 0;
    }

    printf("Enter weighted adjacency matrix (enter 0 where no edge exists):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &input);
            if (i == j) {
                graph[i][j] = INF;
            } else if (input == 0) {
                graph[i][j] = INF;
            } else {
                graph[i][j] = input;
            }
        }
    }

    selected[0] = 1;

    printf("Edges in Minimum Cost Spanning Tree (Prim's):\n");
    for (count = 0; count < n - 1; count++) {
        int min = INF;
        int x = -1, y = -1;

        for (i = 0; i < n; i++) {
            if (selected[i]) {
                for (j = 0; j < n; j++) {
                    if (!selected[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        if (x == -1 || y == -1) {
            break;
        }

        printf("%d - %d : %d\n", x, y, graph[x][y]);
        totalCost += graph[x][y];
        selected[y] = 1;
        edgeCount++;
    }

    if (edgeCount != n - 1) {
        printf("Graph is disconnected. MST not possible.\n");
    } else {
        printf("Total minimum cost = %d\n", totalCost);
    }

    return 0;
}
