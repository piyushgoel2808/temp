/*
 * P10. Write a program to perform a naïve string-matching algorithm.
 * Compatible with Turbo C / Turbo C++
 * Subject: Design and Analysis of Algorithms Lab (MCA-201)
 * Name: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem, Sec-B
 */

#include <stdio.h>
#include <string.h>
#include <conio.h>

int main()
{
    char text[100], pattern[50];
    int i, j, n, m;

    clrscr();

    printf("Enter text: ");
    if (scanf("%s", text) != 1)
    {
        getch();
        return 0;
    }

    printf("Enter pattern: ");
    if (scanf("%s", pattern) != 1)
    {
        getch();
        return 0;
    }

    n = (int)strlen(text);
    m = (int)strlen(pattern);

    for (i = 0; i <= n - m; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m)
            printf("Pattern found at index %d (position %d)\n", i, i + 1);
    }

    getch();
    return 0;
}
