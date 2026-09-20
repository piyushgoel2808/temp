/*
 * Program 12: Implementation of Fractional Knapsack Problem (Greedy Approach)
 * Subject: Design and Analysis of Algorithms Lab (MCA-261 / MCA-201)
 * Name: Rudransh Singh Rawat | Roll No: 06411604425
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    double weight;
    double value;
    double ratio;
} Item;

// Comparison function to sort items based on ratio in descending order
int compare(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    if (itemB->ratio > itemA->ratio) return 1;
    if (itemB->ratio < itemA->ratio) return -1;
    return 0;
}

double fractionalKnapsack(Item items[], int n, double capacity) {
    // Sort items according to value/weight ratio
    qsort(items, n, sizeof(Item), compare);

    double totalValue = 0.0;
    double currentWeight = 0.0;

    printf("Items sorted by Profit/Weight ratio:\n");
    printf(" Item ID | Weight | Value | Ratio (Val/Wt)\n");
    printf("------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("    %d    | %6.1f | %5.1f | %6.2f\n", items[i].id, items[i].weight, items[i].value, items[i].ratio);
    }
    printf("------------------------------------------\n\n");
    printf("Knapsack Allocation Process (Capacity = %.1f):\n", capacity);

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
            printf("  -> Added 100%% of Item %d: +%.1f wt, +%.1f val (Remaining: %.1f)\n",
                   items[i].id, items[i].weight, items[i].value, capacity - currentWeight);
        } else {
            double remain = capacity - currentWeight;
            double fraction = remain / items[i].weight;
            totalValue += items[i].value * fraction;
            currentWeight += remain;
            printf("  -> Added %.2f%% of Item %d: +%.1f wt, +%.1f val (Knapsack Full!)\n",
                   fraction * 100.0, items[i].id, remain, items[i].value * fraction);
            break;
        }
    }

    return totalValue;
}

int main() {
    Item items[] = {
        {1, 10.0, 60.0, 6.0},
        {2, 20.0, 100.0, 5.0},
        {3, 30.0, 120.0, 4.0}
    };
    int n = sizeof(items) / sizeof(items[0]);
    double capacity = 50.0;

    printf("========================================\n");
    printf("     LAB 12: FRACTIONAL KNAPSACK        \n");
    printf("========================================\n");

    double maxValue = fractionalKnapsack(items, n, capacity);

    printf("\nMaximum value obtained in Knapsack: %.2f\n", maxValue);
    printf("========================================\n");

    return 0;
}
