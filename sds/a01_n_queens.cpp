/*
 * A1. Write a program to solve N-QUEENS problem.
 * Subject: Design and Analysis of Algorithms Lab (MCA-201)
 * Name: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem, Sec-B
 */

#include <iostream>
using namespace std;

#define N 8 // Define N for NxN chessboard

void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int board[N][N], int row, int col)
{
    int i, j;

    // Check this row on the left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on the left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQUtil(int board[N][N], int col)
{
    // If all queens are placed, return true
    if (col >= N)
        return true;

    // Try placing queen in all rows one by one for this column
    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            // Place this queen
            board[i][col] = 1;

            // Recur to place the rest of the queens
            if (solveNQUtil(board, col + 1))
                return true;

            // If placing queen doesn't lead to a solution, backtrack
            board[i][col] = 0;
        }
    }
    return false;
}

bool solveNQ()
{
    int board[N][N] = {0};

    if (!solveNQUtil(board, 0))
    {
        cout << "Solution does not exist" << endl;
        return false;
    }

    printSolution(board);
    return true;
}

int main()
{
    solveNQ();
    return 0;
}
