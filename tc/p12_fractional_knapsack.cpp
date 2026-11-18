/*
 * P12. Implement fractional Knapsack using Greedy approach and analyze the algorithm.
 * Compatible with Turbo C++ 3.0
 * Subject: Design and Analysis of Algorithms Lab (MCA-201)
 * Name: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem, Sec-B
 */

#include <iostream.h>
#include <conio.h>

struct Item
{
    int value, weight;
};

void sortItemsByValuePerWeight(Item arr[], int n)
{
    int i, j;
    double r1, r2;
    Item temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            r1 = (double)arr[i].value / arr[i].weight;
            r2 = (double)arr[j].value / arr[j].weight;
            if (r1 < r2)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

double fractionalKnapsack(int W, Item arr[], int n)
{
    int curWeight = 0;
    double finalValue = 0.0;
    int i, remain;

    sortItemsByValuePerWeight(arr, n);

    for (i = 0; i < n; i++)
    {
        if (curWeight + arr[i].weight <= W)
        {
            curWeight += arr[i].weight;
            finalValue += arr[i].value;
        }
        else
        {
            remain = W - curWeight;
            finalValue += arr[i].value * ((double)remain / arr[i].weight);
            break;
        }
    }
    return finalValue;
}

int main()
{
    Item arr[3];
    int W = 50;
    int n = 3;

    clrscr();

    arr[0].value = 60;  arr[0].weight = 10;
    arr[1].value = 100; arr[1].weight = 20;
    arr[2].value = 120; arr[2].weight = 30;

    cout << "Maximum value in Knapsack = " << fractionalKnapsack(W, arr, n) << endl;

    getch();
    return 0;
}
