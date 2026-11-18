/*
 * P16. Implement the Longest Common Subsequence using Dynamic Programming and analyze the algorithm.
 * Subject: Design and Analysis of Algorithms Lab (MCA-201)
 * Name: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem, Sec-B
 */

#include <iostream>
#include <cstring>
using namespace std;

int maxVal(int a, int b)
{
    return (a > b) ? a : b;
}

int lcs(char X[], char Y[], int m, int n)
{
    int L[100][100];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
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
    int L[100][100];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = maxVal(L[i - 1][j], L[i][j - 1]);
        }
    }

    int index = L[m][n];
    char lcsStr[100];
    lcsStr[index] = '\0';

    int i = m, j = n;
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

    cout << "LCS of " << X << " and " << Y << " is " << lcsStr << endl;
}

int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int m = (int)strlen(X);
    int n = (int)strlen(Y);

    cout << "Length of LCS is " << lcs(X, Y, m, n) << endl;
    printLCS(X, Y, m, n);

    return 0;
}
