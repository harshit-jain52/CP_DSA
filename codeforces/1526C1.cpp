#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[2005][2005];
ll a[2005];
int n;
ll func(ll num, int idx)
{
    if (num <= 0)
        return 0;
    if (idx < 0)
        return -1e9 - 10;

    if (dp[idx][num] != -1)
        return dp[idx][num];

    ll h = func(num, idx - 1);
    ll t = a[idx] + func(num - 1, idx - 1);
    if (t >= 0)
    {
        h = max(h, t);
    }

    return dp[idx][num] = h;
}
int main()
{
    memset(dp, -1, sizeof(dp));

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = n; i >= 0; i--)
    {
        if (func(i, n - 1) >= 0)
        {
            cout << i << endl;
            break;
        }
    }
}