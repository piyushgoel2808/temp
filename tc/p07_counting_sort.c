/*
 * P7. Write a program to perform counting sort on a given list of numbers.
 * Compatible with Turbo C / Turbo C++
 * Subject: Design and Analysis of Algorithms Lab (MCA-201)
 * Name: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem, Sec-B
 */

#include <stdio.h>
#include <conio.h>

int main()
{
    int a[50], count[100];
    int n, i, j, max;

    clrscr();

    for (i = 0; i < 100; i++)
        count[i] = 0;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        getch();
        return 0;
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

    getch();
    return 0;
}
