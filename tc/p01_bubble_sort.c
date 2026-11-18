/*
 * P1. Write a program to implement bubble sort.
 * Compatible with Turbo C / Turbo C++
 * Subject: Design and Analysis of Algorithms Lab (MCA-201)
 * Name: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem, Sec-B
 */

#include <stdio.h>
#include <conio.h>

void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[100], n, i;

    clrscr();

    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        getch();
        return 0;
    }

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    getch();
    return 0;
}
