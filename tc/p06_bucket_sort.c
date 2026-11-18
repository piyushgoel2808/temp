/*
 * P6. Write a program to perform bucket sort on a given list of numbers.
 * Compatible with Turbo C / Turbo C++
 * Subject: Design and Analysis of Algorithms Lab (MCA-201)
 * Name: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem, Sec-B
 */

#include <stdio.h>
#include <conio.h>

void bucketSort(float a[], int n)
{
    float bucket[10][50];
    int count[10];
    int i, j, k;
    int index;
    float temp;

    for (i = 0; i < 10; i++)
        count[i] = 0;

    for (i = 0; i < n; i++)
    {
        index = (int)(a[i] * 10);
        if (index >= 10)
            index = 9;
        if (index < 0)
            index = 0;
        bucket[index][count[index]] = a[i];
        count[index]++;
    }

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < count[i] - 1; j++)
        {
            for (k = 0; k < count[i] - j - 1; k++)
            {
                if (bucket[i][k] > bucket[i][k + 1])
                {
                    temp = bucket[i][k];
                    bucket[i][k] = bucket[i][k + 1];
                    bucket[i][k + 1] = temp;
                }
            }
        }
    }

    k = 0;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < count[i]; j++)
            a[k++] = bucket[i][j];
    }
}

int main()
{
    float a[50];
    int n, i;

    clrscr();

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        getch();
        return 0;
    }

    printf("Enter numbers between 0 and 1: ");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &a[i]);
    }

    bucketSort(a, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%g ", a[i]);
    }
    printf("\n");

    getch();
    return 0;
}
