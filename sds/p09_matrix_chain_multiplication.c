/*
 * P9. WAP to Implement Matrix Chain Multiplication.
 * Subject: Design and Analysis of Algorithms Lab (MCA-201)
 * Name: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem, Sec-B
 */

#include <stdio.h>

int main()
{
    int p[20], m[20][20];
    int n, i, j, k, q;

    printf("Enter number of matrices: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Enter dimensions of matrices:\n");
    for (i = 0; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }

    for (i = 1; i <= n; i++)
        m[i][i] = 0;

    for (int L = 2; L <= n; L++)
    {
        for (i = 1; i <= n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = 999999;
            for (k = i; k < j; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    printf("Minimum number of multiplications = %d\n", m[1][n]);

    return 0;
}
