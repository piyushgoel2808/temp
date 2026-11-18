/*
 * P10. Write a program to perform a naïve string-matching algorithm.
 * Subject: Design and Analysis of Algorithms Lab (MCA-201)
 * Name: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem, Sec-B
 */

#include <stdio.h>
#include <string.h>

int main()
{
    char text[100], pattern[50];
    int i, j;

    printf("Enter text: ");
    if (scanf("%s", text) != 1) return 1;

    printf("Enter pattern: ");
    if (scanf("%s", pattern) != 1) return 1;

    int n = (int)strlen(text);
    int m = (int)strlen(pattern);

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

    return 0;
}
