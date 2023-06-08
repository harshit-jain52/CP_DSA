#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 1;

// O(NlogN)
int main()
{

    int n;
    cin >> n;
    int dp[n + 1];
    vector<ll> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    dp[0] = -INF;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = INF;
    }

    // dp[l] = least element at which increasing subsequence of length l ends

    for (int i = 0; i < n; i++)
    {
        auto l = upper_bound(dp, dp + n + 1, x[i]) - dp;
        if (dp[l - 1] < x[i])
            dp[l] = x[i];
    }

    int ans = lower_bound(dp, dp + n + 1, INF) - dp - 1;

    cout << ans;
}