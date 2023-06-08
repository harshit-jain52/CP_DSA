#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
int dp[N][2];
ll a[N];
int n;
int func(int idx, bool changed)
{
    if (dp[idx][changed] != -1)
        return dp[idx][changed];

    int ct = 1;
    if (idx > 0 && a[idx] > a[idx - 1])
    {
        ct = 1 + func(idx - 1, changed);
    }
    else if (idx > 0 && !changed)
    {
        ct = 2;
    }

    if (idx > 1 && !changed && a[idx] - a[idx - 2] > 1)
    {
        ct = max(ct, 2 + func(idx - 2, true));
    }

    return dp[idx][changed] = ct;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof(dp));

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, func(i, 0));
        if (i > 0)
            mx = max(mx, 1 + func(i - 1, 1));
        // cout << func(i, 0) << " ";
    }

    cout << mx;
}