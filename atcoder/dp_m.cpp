#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    ll aPrefix[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    aPrefix[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        aPrefix[i] = a[i] + aPrefix[i - 1];
    }

    if (aPrefix[n - 1] < k)
    {
        cout << 0;
        return;
    }

    int dp[n][k + 1];
    int dpPrefix[n][k + 1];

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
        dpPrefix[i][0] = 1;
    }

    for (int j = 1; j <= k; j++)
    {
        if (j <= aPrefix[0])
            dp[0][j] = 1;
        else
            dp[0][j] = 0;

        dpPrefix[0][j] = dp[0][j] + dpPrefix[0][j - 1];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (j > aPrefix[i])
                dp[i][j] = 0;
            else if (j <= a[i])
                dp[i][j] = dpPrefix[i - 1][j];
            else
                dp[i][j] = (dpPrefix[i - 1][j] + M - dpPrefix[i - 1][j - a[i] - 1]) % M;

            dpPrefix[i][j] = (dp[i][j] + dpPrefix[i][j - 1]) % M;
        }
    }

    cout << dp[n - 1][k];
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}