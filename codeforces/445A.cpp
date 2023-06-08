#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, i, j;
    char chessman[2] = {'B', 'W'};

    cin >> n >> m;

    char board[n][m];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (board[i][j] == '.')
                cout << chessman[(i + j) % 2];
            else
                cout << board[i][j];
        }
        cout << endl;
    }
}