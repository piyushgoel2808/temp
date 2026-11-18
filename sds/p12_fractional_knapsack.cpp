/*
 * P12. Implement fractional Knapsack using Greedy approach and analyze the algorithm.
 * Subject: Design and Analysis of Algorithms Lab (MCA-201)
 * Name: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem, Sec-B
 */

#include <iostream>
using namespace std;

struct Item
{
    int value, weight;
};

void sortItemsByValuePerWeight(Item arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double r1 = (double)arr[i].value / arr[i].weight;
            double r2 = (double)arr[j].value / arr[j].weight;
            if (r1 < r2)
            {
                Item temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

double fractionalKnapsack(int W, Item arr[], int n)
{
    sortItemsByValuePerWeight(arr, n);
    int curWeight = 0;
    double finalValue = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (curWeight + arr[i].weight <= W)
        {
            curWeight += arr[i].weight;
            finalValue += arr[i].value;
        }
        else
        {
            int remain = W - curWeight;
            finalValue += arr[i].value * ((double)remain / arr[i].weight);
            break;
        }
    }
    return finalValue;
}

int main()
{
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int W = 50;
    int n = 3;

    cout << "Maximum value in Knapsack = " << fractionalKnapsack(W, arr, n) << endl;

    return 0;
}
