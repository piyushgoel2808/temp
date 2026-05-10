// Manage an undirected graph using an adjacency matrix.
#include <stdio.h>

#define MAX 20

int main() {
    int adj[MAX][MAX] = {0};
    int n = 0;
    int choice, u, v, i, j;

    // Continue until the user exits the graph menu.
    do {
        printf("\n1. Insert vertex\n2. Insert edge\n3. Delete vertex\n4. Delete edge\n5. Degree of each vertex\n6. Number of self-loops\n7. Display adjacency matrix\n8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add a new vertex by increasing the active size.
                if (n == MAX) {
                    printf("Vertex limit reached.\n");
                } else {
                    n++;
                    printf("Vertex %d inserted.\n", n - 1);
                }
                break;

            case 2:
                // Connect two existing vertices with an undirected edge.
                printf("Enter two vertices (u v): ");
                scanf("%d %d", &u, &v);
                if (u >= 0 && u < n && v >= 0 && v < n) {
                    adj[u][v] = 1;
                    adj[v][u] = 1;
                    printf("Edge inserted.\n");
                } else {
                    printf("Invalid vertices.\n");
                }
                break;

            case 3:
                // Remove a vertex by shifting the remaining rows and columns.
                printf("Enter vertex to delete: ");
                scanf("%d", &u);
                if (u < 0 || u >= n) {
                    printf("Invalid vertex.\n");
                    break;
                }

                for (i = u; i < n - 1; i++) {
                    for (j = 0; j < n; j++) {
                        adj[i][j] = adj[i + 1][j];
                    }
                }

                for (j = u; j < n - 1; j++) {
                    for (i = 0; i < n - 1; i++) {
                        adj[i][j] = adj[i][j + 1];
                    }
                }

                n--;
                printf("Vertex deleted.\n");
                break;

            case 4:
                // Delete the undirected edge between two vertices.
                printf("Enter two vertices (u v): ");
                scanf("%d %d", &u, &v);
                if (u >= 0 && u < n && v >= 0 && v < n) {
                    adj[u][v] = 0;
                    adj[v][u] = 0;
                    printf("Edge deleted.\n");
                } else {
                    printf("Invalid vertices.\n");
                }
                break;

            case 5:
                // Degree counts all incident edges for each vertex.
                if (n == 0) {
                    printf("No vertices in graph.\n");
                } else {
                    for (i = 0; i < n; i++) {
                        int degree = 0;
                        for (j = 0; j < n; j++) {
                            if (i == j) {
                                degree += 2 * adj[i][j];
                            } else {
                                degree += adj[i][j];
                            }
                        }
                        printf("Degree of vertex %d = %d\n", i, degree);
                    }
                }
                break;

            case 6: {
                // Self-loops appear on the diagonal of the matrix.
                int loops = 0;
                for (i = 0; i < n; i++) {
                    if (adj[i][i] != 0) {
                        loops++;
                    }
                }
                printf("Number of self-loops = %d\n", loops);
                break;
            }

            case 7:
                // Show the raw adjacency matrix for the current graph.
                if (n == 0) {
                    printf("Graph is empty.\n");
                } else {
                    printf("Adjacency Matrix:\n");
                    for (i = 0; i < n; i++) {
                        for (j = 0; j < n; j++) {
                            printf("%d ", adj[i][j]);
                        }
                        printf("\n");
                    }
                }
                break;

            case 8:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 8);

    return 0;
}
