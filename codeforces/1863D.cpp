#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

bool solve()
{
    int n, m, i, j;
    cin >> n >> m;
    char dom[n][m];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> dom[i][j];
        }
    }

    int left[n][m], up[n][m];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (i == 0)
                left[i][j] = (dom[i][j] == 'L');
            else
                left[i][j] = (dom[i][j] == 'L') + left[i - 1][j];

            if (j == 0)
                up[i][j] = (dom[i][j] == 'U');
            else
                up[i][j] = (dom[i][j] == 'U') + up[i][j - 1];
        }
    }

    for (i = 0; i < n; i++)
    {
        if (up[i][m - 1] % 2 == 1)
        {
            return false;
        }
    }

    for (j = 0; j < m; j++)
    {
        if (left[n - 1][j] % 2 == 1)
        {
            return false;
        }
    }

    int toprint[n][m];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (dom[i][j] == 'L')
            {
                if (left[i][j] % 2)
                    toprint[i][j] = 1;
                else
                    toprint[i][j] = -1;
            }
            else if (dom[i][j] == 'U')
            {
                if (up[i][j] % 2)
                    toprint[i][j] = 1;
                else
                    toprint[i][j] = -1;
            }
            else if (dom[i][j] == 'R')
                toprint[i][j] = -toprint[i][j - 1];
            else if (dom[i][j] == 'D')
                toprint[i][j] = -toprint[i - 1][j];
            else
                toprint[i][j] = 0;
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (toprint[i][j] == 1)
                cout << 'W';
            else if (toprint[i][j] == -1)
                cout << 'B';
            else
                cout << '.';
        }
        cout << endl;
    }

    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        if (!solve())
            cout << -1 << endl;
    }
}