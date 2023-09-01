#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 10;

int fen[N][N];

void update(int y, int x, ll val)
{
    for (int i = y; i < N; i += (i & -i))
        for (int j = x; j < N; j += (j & -j))
            fen[i][j] += val;
}

int sum(int y, int x)
{
    int ans = 0;
    for (int i = y; i > 0; i -= (i & -i))
        for (int j = x; j > 0; j -= (j & (-j)))
            ans += fen[i][j];

    return ans;
}

int main()
{
    int n, q;
    cin >> n >> q;

    int forest[n + 10][n + 10];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char c;
            cin >> c;
            forest[i][j] = (int)(c == '*');
            update(i, j, forest[i][j]);
        }
    }
    
    /*
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << forest[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << sum(i, j) << " ";
        }
        cout << endl;
    }
    */

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int y, x;
            cin >> y >> x;
            if (forest[y][x] == 1)
            {
                update(y, x, -1);
                forest[y][x] = 0;
            }
            else
            {
                update(y, x, 1);
                forest[y][x] = 1;
            }
        }
        else
        {
            int y1, x1, y2, x2;
            cin >> y1 >> x1 >> y2 >> x2;

            cout << (sum(y2, x2) - sum(y1 - 1, x2) - sum(y2, x1 - 1) + sum(y1 - 1, x1 - 1)) << endl;
        }
    }
}
