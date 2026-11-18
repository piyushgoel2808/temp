/*
 * P17. Implement Matrix Chain Multiplication using Dynamic Programming and analyze the algorithm.
 * Subject: Design and Analysis of Algorithms Lab (MCA-201)
 * Name: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem, Sec-B
 */

#include <iostream>
using namespace std;

int matrixChainMultiplication(int p[], int n)
{
    int m[100][100];

    for (int i = 1; i < n; i++)
    {
        m[i][i] = 0;
    }

    for (int l = 2; l < n; l++)
    {
        for (int i = 1; i < n - l + 1; i++)
        {
            int j = i + l - 1;
            m[i][j] = 100000;

            for (int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
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

    cout << "Minimum number of multiplications is: "
         << matrixChainMultiplication(arr, size) << endl;

    return 0;
}
