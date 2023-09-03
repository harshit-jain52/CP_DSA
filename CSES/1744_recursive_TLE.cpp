#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int dp[505][505];

int cuts(int x, int y)
{
    if (x == y)
        return 0;
    if (x == 1)
        return y - 1;
    if (y == 1)
        return x - 1;

    if (dp[x][y] != -1)
        return dp[x][y];

    int ct = 1e9;

    for (int i = 1; i <= x - 1; i++)
    {
        ct = min(ct, 1 + cuts(i, y) + cuts(x - i, y));
    }

    for (int j = 1; j <= y - 1; j++)
    {
        ct = min(ct, 1 + cuts(x, j) + cuts(x, y - j));
    }

    return dp[x][y] = ct;
}

int main()
{
    memset(dp, -1, sizeof(dp));

    int a, b;
    cin >> a >> b;

    cout << cuts(a, b);
}