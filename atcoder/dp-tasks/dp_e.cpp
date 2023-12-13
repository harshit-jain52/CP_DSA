#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;

ll wt[110];
ll val[110];
ll dp[110][N];

ll func(int idx, ll value_left)
{
    if (value_left == 0)
        return 0;
    if (idx < 0)
        return 1e15;

    if (dp[idx][value_left] != -1)
        return dp[idx][value_left];

    ll min_wt = func(idx - 1, value_left);
    if (value_left >= val[idx])
        min_wt = min(min_wt, wt[idx] + func(idx - 1, value_left - val[idx]));

    return dp[idx][value_left] = min_wt;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    ll w;
    cin >> n >> w;

    for (int i = 0; i < n; i++)
    {
        cin >> wt[i] >> val[i];
    }

    for (int i = N - 1; i >= 0; i--)
    {
        if (func(n - 1, i) <= w)
        {
            cout << i;
            break;
        }
    }
}