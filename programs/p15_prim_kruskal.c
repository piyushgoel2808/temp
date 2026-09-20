/*
 * Program 15: Implementation of Prim's and Kruskal's Minimum Spanning Tree (MST)
 * Subject: Design and Analysis of Algorithms Lab (MCA-261 / MCA-201)
 * Name: Rudransh Singh Rawat | Roll No: 06411604425
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define V 5

// ---------------- PRIM'S ALGORITHM ----------------
int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void primMST(int graph[V][V]) {
    int parent[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int totalWeight = 0;
    printf("\n--- Prim's Algorithm MST Edges ---\n");
    printf(" Edge   | Weight\n");
    printf("----------------\n");
    for (int i = 1; i < V; i++) {
        printf(" %d - %d  |   %2d\n", parent[i], i, graph[i][parent[i]]);
        totalWeight += graph[i][parent[i]];
    }
    printf("----------------\n");
    printf("Total Cost of Prim's MST = %d\n", totalWeight);
}

// ---------------- KRUSKAL'S ALGORITHM ----------------
struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent;
    int rank;
};

int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int compareEdges(const void *a, const void *b) {
    struct Edge *a1 = (struct Edge *)a;
    struct Edge *b1 = (struct Edge *)b;
    return a1->weight - b1->weight;
}

void kruskalMST(struct Edge edges[], int E) {
    qsort(edges, E, sizeof(struct Edge), compareEdges);

    struct Subset *subsets = (struct Subset *)malloc(V * sizeof(struct Subset));
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    struct Edge result[V];
    int e = 0; // Index for result[]
    int i = 0; // Index for sorted edges

    while (e < V - 1 && i < E) {
        struct Edge next_edge = edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    int totalWeight = 0;
    printf("\n--- Kruskal's Algorithm MST Edges ---\n");
    printf(" Edge   | Weight\n");
    printf("----------------\n");
    for (i = 0; i < e; ++i) {
        printf(" %d - %d  |   %2d\n", result[i].src, result[i].dest, result[i].weight);
        totalWeight += result[i].weight;
    }
    printf("----------------\n");
    printf("Total Cost of Kruskal's MST = %d\n", totalWeight);

    free(subsets);
}

int main() {
    // Weighted graph with 5 vertices (0 to 4)
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    struct Edge edges[] = {
        {0, 1, 2}, {0, 3, 6},
        {1, 2, 3}, {1, 3, 8}, {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };
    int E = sizeof(edges) / sizeof(edges[0]);

    printf("========================================\n");
    printf("   LAB 15: PRIM'S & KRUSKAL'S MST       \n");
    printf("========================================\n");

    primMST(graph);
    kruskalMST(edges, E);

    printf("========================================\n");

    return 0;
}
