#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;

int wt[110];
ll val[110];
ll dp[110][N];

ll func(int idx, int wt_left)
{
    if (idx < 0 || wt_left == 0)
        return 0;
    if (dp[idx][wt_left] != -1)
        return dp[idx][wt_left];

    ll ans = 0;
    ans = max(ans, func(idx - 1, wt_left));
    if (wt_left >= wt[idx])
    {
        ans = max(ans, val[idx] + func(idx - 1, wt_left - wt[idx]));
    }
    return dp[idx][wt_left] = ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n, w;
    cin >> n >> w;

    for (int i = 0; i < n; i++)
    {
        cin >> wt[i] >> val[i];
    }

    cout << func(n - 1, w);
}