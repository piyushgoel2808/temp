/*
 * P16. Implement the Longest Common Subsequence using Dynamic Programming and analyze the algorithm.
 * Compatible with Turbo C++ 3.0
 * Subject: Design and Analysis of Algorithms Lab (MCA-201)
 * Name: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem, Sec-B
 */

#include <iostream.h>
#include <string.h>
#include <conio.h>

int maxVal(int a, int b)
{
    return (a > b) ? a : b;
}

int lcs(char X[], char Y[], int m, int n)
{
    int L[50][50];
    int i, j;

    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = maxVal(L[i - 1][j], L[i][j - 1]);
        }
    }
    return L[m][n];
}

void printLCS(char X[], char Y[], int m, int n)
{
    int L[50][50];
    int i, j, index;
    char lcsStr[50];

    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = maxVal(L[i - 1][j], L[i][j - 1]);
        }
    }

    index = L[m][n];
    lcsStr[index] = '\0';

    i = m;
    j = n;
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            lcsStr[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        }
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    cout << "LCS of " << X << " and " << Y << " is " << lcsStr << "\n";
}

int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int m = strlen(X);
    int n = strlen(Y);

    clrscr();

    cout << "Length of LCS is " << lcs(X, Y, m, n) << "\n";
    printLCS(X, Y, m, n);

    getch();
    return 0;
}
