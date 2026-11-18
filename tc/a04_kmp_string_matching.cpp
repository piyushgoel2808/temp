/*
 * A4 / P22. WAP to implement Knuth Morris Pratt algorithm.
 * Compatible with Turbo C++ 3.0
 * Subject: Design and Analysis of Algorithms Lab (MCA-201)
 * Name: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem, Sec-B
 */

#include <iostream.h>
#include <string.h>
#include <conio.h>

void computeLPSArray(char pattern[], int M, int lps[])
{
    int len = 0;
    int i;
    lps[0] = 0;

    for (i = 1; i < M; i++)
    {
        while (len > 0 && pattern[i] != pattern[len])
        {
            len = lps[len - 1];
        }
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
        }
        else
        {
            lps[i] = 0;
        }
    }
}

void KMP(char text[], char pattern[])
{
    int N = strlen(text);
    int M = strlen(pattern);
    int lps[50];
    int i = 0, j = 0;
    int found = 0;

    computeLPSArray(pattern, M, lps);

    while (i < N)
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }

        if (j == M)
        {
            cout << "Pattern found at index " << (i - j) << "\n";
            j = lps[j - 1];
            found = 1;
        }
        else if (i < N && pattern[j] != text[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }

    if (!found)
    {
        cout << "Pattern not found in the text.\n";
    }
}

int main()
{
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABABCABAB";

    clrscr();

    KMP(text, pattern);

    getch();
    return 0;
}
