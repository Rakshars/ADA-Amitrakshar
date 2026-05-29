#include <stdio.h>

#define MAX 20

int board[MAX][MAX];
int N;

int isSafe(int row, int col)
{
    int i;

    for (i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
            return 0;
    }

    for (i = 1; row - i >= 0 && col - i >= 0; i++)
    {
        if (board[row - i][col - i] == 1)
            return 0;
    }

    for (i = 1; row - i >= 0 && col + i < N; i++)
    {
        if (board[row - i][col + i] == 1)
            return 0;
    }

    return 1;
}

int solveNQueens(int row)
{
    int col;

    if (row == N)
        return 1;

    for (col = 0; col < N; col++)
    {
        if (isSafe(row, col))
        {
            board[row][col] = 1;

            if (solveNQueens(row + 1))
                return 1;

            board[row][col] = 0;
        }
    }

    return 0;
}

void printBoard()
{
    int i, j;

    printf("\nSolution:\n\n");

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (board[i][j] == 1)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

int main()
{
    int i, j;

    printf("Enter value of N: ");
    scanf("%d", &N);

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            board[i][j] = 0;
        }
    }

    if (solveNQueens(0))
        printBoard();
    else
        printf("No solution exists.\n");

    return 0;
}