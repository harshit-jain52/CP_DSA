#include <bits/stdc++.h>
using namespace std;

int dp[1000005];

int func(int amt, vector<int> &coins)
{
    if (amt == 0)
    {
        return 0;
    }

    if (dp[amt] != -1)
        return dp[amt];

    int ct = INT_MAX;
    for (auto coin : coins)
    {
        if (amt >= coin)
        {
            ct = min(ct + 0LL, 1LL + func(amt - coin, coins));
        }
    }
    return dp[amt] = ct;
}

int main()
{
    memset(dp, -1, sizeof(dp));

    int n, x;
    cin >> n >> x;
    vector<int> c(n);

    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    int ans = func(x, c);

    cout << ((ans == INT_MAX) ? -1 : ans);
}