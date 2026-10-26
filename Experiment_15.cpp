//Write a program to solve the N-Queens problem using the Backtracking technique.
#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<int> &board, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

bool solveNQueens(vector<int> &board, int row, int n)
{
    if (row == n)
        return true;

    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col))
        {
            board[row] = col;

            if (solveNQueens(board, row + 1, n))
                return true;

            board[row] = -1;
        }
    }

    return false;
}

int main()
{
    int n;

    printf("\nEnter number of queens: ");
    cin >> n;

    vector<int> board(n, -1);

    if (solveNQueens(board, 0, n))
    {
        printf("\nSolution to N-Queens problem:\n");

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i] == j)
                    cout << "Q ";
                else
                    cout << ". ";
            }
            cout << endl;
        }
    }
    else
    {
        printf("\nNo solution exists.\n");
    }

    return 0;
}
//Name- Hari krishna k
// Branch - CSDA
//Roll no. - 25/DA/028