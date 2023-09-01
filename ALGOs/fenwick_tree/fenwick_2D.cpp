#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e3;

// Binary Indexed Tree
// 1-based indexing

ll fen[N][N];

/*
Query Types:
1. Point Updates (Addition)
2. Range Sum
*/

void update(int x, int y, ll val)
{
    for (int i = x; i < N; i += (i & -i))
        for (int j = y; j < N; j += (j & -j))
            fen[i][j] += val;
}

ll sum(int x, int y) // sum from 0 to ith index
{
    ll ans = 0;
    for (int i = x; i > 0; i -= (i & -i))
        for (int j = y; j > 0; j -= (j & (-j)))
            ans += fen[i][j];

    return ans;
}

int main()
{
    int n, q;
    cin >> n >> q;

    int a[n + 10][n + 10];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            update(i, j, a[i][j]);
        }
    }

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x, y;
            ll val;
            cin >> x >> y >> val;
            update(x, y, val);
        }
        else
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            cout << sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1);
        }
    }
}
