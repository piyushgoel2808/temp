/*
 * P17. Implement Matrix Chain Multiplication using Dynamic Programming and analyze the algorithm.
 * Compatible with Turbo C++ 3.0
 * Subject: Design and Analysis of Algorithms Lab (MCA-201)
 * Name: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem, Sec-B
 */

#include <iostream.h>
#include <conio.h>

long matrixChainMultiplication(int p[], int n)
{
    long m[20][20];
    int i, l, j, k;
    long q;

    for (i = 1; i < n; i++)
    {
        m[i][i] = 0;
    }

    for (l = 2; l < n; l++)
    {
        for (i = 1; i < n - l + 1; i++)
        {
            j = i + l - 1;
            m[i][j] = 100000L;

            for (k = i; k <= j - 1; k++)
            {
                q = m[i][k] + m[k + 1][j] + (long)p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                }
            }
        }
    }
    return m[1][n - 1];
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    clrscr();

    cout << "Minimum number of multiplications is: "
         << matrixChainMultiplication(arr, size) << "\n";

    getch();
    return 0;
}
