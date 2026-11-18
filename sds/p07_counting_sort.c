/*
 * P7. Write a program to perform counting sort on a given list of numbers.
 * Subject: Design and Analysis of Algorithms Lab (MCA-201)
 * Name: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem, Sec-B
 */

#include <stdio.h>

int main()
{
    int a[50], count[100] = {0};
    int n, i, j, max;

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

    max = a[0];
    for (i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }

    for (i = 0; i < n; i++)
        count[a[i]]++;

    j = 0;
    for (i = 0; i <= max; i++)
    {
        while (count[i] > 0)
        {
            a[j] = i;
            j++;
            count[i]--;
        }
    }

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
