/*
 * P2. Write a program to implement quick sort.
 * Compatible with Turbo C / Turbo C++
 * Subject: Design and Analysis of Algorithms Lab (MCA-201)
 * Name: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem, Sec-B
 */

#include <stdio.h>
#include <conio.h>

void quickSort(int a[], int low, int high)
{
    int i, j, pivot, temp;
    if (low < high)
    {
        pivot = a[high];
        i = low - 1;
        for (j = low; j < high; j++)
        {
            if (a[j] < pivot)
            {
                i++;
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        temp = a[i + 1];
        a[i + 1] = a[high];
        a[high] = temp;

        quickSort(a, low, i);
        quickSort(a, i + 2, high);
    }
}

int main()
{
    int a[50], n, i;

    clrscr();

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

    quickSort(a, 0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    getch();
    return 0;
}
