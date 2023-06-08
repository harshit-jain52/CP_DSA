#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
int dp[N][2];
ll a[N];

int func(int idx, bool skipped)
{
    if (dp[idx][skipped] != -1)
        return dp[idx][skipped];

    int ct = 1;
    if (idx > 0 && a[idx] > a[idx - 1])
    {
        ct = 1 + func(idx - 1, skipped);
    }
    if (idx > 1 && !skipped && a[idx] > a[idx - 2])
    {
        ct = max(ct, 1 + func(idx - 2, true));
    }
    return dp[idx][skipped] = ct;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, func(i, 0));
    }

    cout << mx;
}