#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N = 1010;
const int M = 1e9 + 7;

char a[N][N];
ll dp[N][N];

ll func(int i, int j)
{
    if (i < 1 || j < 1)
        return 0;
    if (a[i][j] == '#')
        return 0;
    if (i == 1 && j == 1)
        return 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    ll ans = 0;
    ans = (ans % M + func(i - 1, j) % M) % M;
    ans = (ans % M + func(i, j - 1) % M) % M;

    return dp[i][j] = ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof(dp));

    int h, w;
    cin >> h >> w;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << func(h, w);
}