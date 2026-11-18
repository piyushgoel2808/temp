/*
 * P5. Write a program to perform radix sort on a given list of numbers.
 * Subject: Design and Analysis of Algorithms Lab (MCA-201)
 * Name: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem, Sec-B
 */

#include <stdio.h>

int getMax(int a[], int n)
{
    int max = a[0], i;
    for (i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

void radixSort(int a[], int n)
{
    int i, exp, max;
    int output[100];

    max = getMax(a, n);

    for (exp = 1; max / exp > 0; exp = exp * 10)
    {
        int count[10] = {0};

        for (i = 0; i < n; i++)
            count[(a[i] / exp) % 10]++;

        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (i = n - 1; i >= 0; i--)
        {
            output[count[(a[i] / exp) % 10] - 1] = a[i];
            count[(a[i] / exp) % 10]--;
        }

        for (i = 0; i < n; i++)
            a[i] = output[i];
    }
}

int main()
{
    int a[50], n, i;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    radixSort(a, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
