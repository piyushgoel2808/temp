/*
 * A1 / P19. Write a program to solve N-QUEENS problem.
 * Compatible with Turbo C++ 3.0
 * Subject: Design and Analysis of Algorithms Lab (MCA-201)
 * Name: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem, Sec-B
 */

#include <iostream.h>
#include <conio.h>

#define N 8

void printSolution(int board[N][N])
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}

int isSafe(int board[N][N], int row, int col)
{
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return 0;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return 0;

    return 1;
}

int solveNQUtil(int board[N][N], int col)
{
    int i;
    if (col >= N)
        return 1;

    for (i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;

            if (solveNQUtil(board, col + 1))
                return 1;

            board[i][col] = 0;
        }
    }
    return 0;
}

int solveNQ()
{
    int board[N][N];
    int i, j;

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            board[i][j] = 0;

    if (!solveNQUtil(board, 0))
    {
        cout << "Solution does not exist\n";
        return 0;
    }

    printSolution(board);
    return 1;
}

int main()
{
    clrscr();

    solveNQ();

    getch();
    return 0;
}
