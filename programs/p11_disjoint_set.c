/*
 * Program 11: Implementation and Analysis of Disjoint Data Structure (Union-Find)
 * Subject: Design and Analysis of Algorithms Lab (MCA-261 / MCA-201)
 * Name: Rudransh Singh Rawat | Roll No: 06411604425
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Disjoint Set Structure
typedef struct {
    int parent[MAX_NODES];
    int rank[MAX_NODES];
    int n;
} DisjointSet;

// Initialize Disjoint Set
void makeSet(DisjointSet *ds, int n) {
    ds->n = n;
    for (int i = 0; i < n; i++) {
        ds->parent[i] = i;
        ds->rank[i] = 0;
    }
}

// Find operation with Path Compression
int findSet(DisjointSet *ds, int i) {
    if (ds->parent[i] != i) {
        ds->parent[i] = findSet(ds, ds->parent[i]); // Path compression
    }
    return ds->parent[i];
}

// Union operation by Rank
void unionSet(DisjointSet *ds, int i, int j) {
    int root_i = findSet(ds, i);
    int root_j = findSet(ds, j);

    if (root_i == root_j) {
        printf("  Elements %d and %d are already in the same set (Representative: %d)\n", i, j, root_i);
        return;
    }

    if (ds->rank[root_i] < ds->rank[root_j]) {
        ds->parent[root_i] = root_j;
        printf("  Union(%d, %d): Root %d attached under Root %d\n", i, j, root_i, root_j);
    } else if (ds->rank[root_i] > ds->rank[root_j]) {
        ds->parent[root_j] = root_i;
        printf("  Union(%d, %d): Root %d attached under Root %d\n", i, j, root_j, root_i);
    } else {
        ds->parent[root_j] = root_i;
        ds->rank[root_i]++;
        printf("  Union(%d, %d): Root %d attached under Root %d, new rank: %d\n", i, j, root_j, root_i, ds->rank[root_i]);
    }
}

int main() {
    DisjointSet ds;
    int n = 7; // Elements 0 through 6
    makeSet(&ds, n);

    printf("========================================\n");
    printf("   LAB 11: DISJOINT SET DATA STRUCTURE \n");
    printf("========================================\n");
    printf("Initialized 7 disjoint sets: {0}, {1}, {2}, {3}, {4}, {5}, {6}\n\n");

    printf("Performing Union operations:\n");
    unionSet(&ds, 0, 1);
    unionSet(&ds, 1, 2);
    unionSet(&ds, 3, 4);
    unionSet(&ds, 5, 6);
    unionSet(&ds, 4, 5);

    printf("\nSet Membership Queries:\n");
    printf("  Find(2) Representative: %d\n", findSet(&ds, 2));
    printf("  Find(0) Representative: %d\n", findSet(&ds, 0));
    printf("  Find(6) Representative: %d\n", findSet(&ds, 6));
    printf("  Find(3) Representative: %d\n", findSet(&ds, 3));

    printf("\nChecking connectivity:\n");
    if (findSet(&ds, 0) == findSet(&ds, 2))
        printf("  Elements 0 and 2 belong to the SAME connected component.\n");
    else
        printf("  Elements 0 and 2 belong to DIFFERENT components.\n");

    if (findSet(&ds, 1) == findSet(&ds, 5))
        printf("  Elements 1 and 5 belong to the SAME connected component.\n");
    else
        printf("  Elements 1 and 5 belong to DIFFERENT components.\n");

    printf("========================================\n");

    return 0;
}
