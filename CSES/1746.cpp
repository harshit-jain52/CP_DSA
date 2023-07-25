#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1, M = 1e9 + 7;
int dp[N][101];
int x[N], m;

int func(int idx, int num)
{
    if (idx == 0)
        return (x[idx] == 0 || x[idx] == num);
    if (dp[idx][num] != -1)
        return dp[idx][num];

    int ct = 0;

    if (x[idx] == 0 || x[idx] == num)
    {
        ct = (ct + func(idx - 1, num)) % M;
        if (num > 1)
            ct = (ct + func(idx - 1, num - 1)) % M;
        if (num < m)
            ct = (ct + func(idx - 1, num + 1)) % M;
    }

    return dp[idx][num] = ct;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ans = (ans + func(n - 1, i)) % M;
    }
    cout << ans;
}