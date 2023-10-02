#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

bool isSafe(int row, int col, char board[][8])
{
    if (board[row][col] != '.')
        return false;

    // Check in row
    int i, j;
    for (i = 0; i <= col; i++)
        if (board[row][i] == 'Q')
            return false;

    // Check diagonally
    i = row - 1, j = col - 1;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 'Q')
            return false;

        i--;
        j--;
    }

    i = row + 1, j = col - 1;
    while (i < 8 && j >= 0)
    {
        if (board[i][j] == 'Q')
            return false;

        i++;
        j--;
    }

    return true;
}
int ways(char board[][8], int col)
{
    if (col >= 8)
        return 1;

    int ct = 0;
    for (int row = 0; row < 8; row++)
    {
        if (isSafe(row, col, board))
        {
            board[row][col] = 'Q';
            ct += ways(board, col + 1);
            board[row][col] = '.';
        }
    }

    return ct;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char board[8][8];

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> board[i][j];
        }
    }

    cout << ways(board, 0);
}