#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int INF = 1e9 + 1;

void solve()
{
    int n;
    cin >> n;
    int a[n], len[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int dp[n + 1];
    dp[0] = -INF;
    for (int i = 1; i <= n; i++)
        dp[i] = INF;

    for (int i = 0; i < n; i++)
    {
        auto l = upper_bound(dp, dp + n + 1, a[i]) - dp;
        if (dp[l - 1] < a[i])
        {
            len[i] = l;
            dp[l] = a[i];
        }
        else
        {
            len[i] = l - 1;
        }
    }

    int ans = lower_bound(dp, dp + n + 1, INF) - dp - 1;
    map<int, int> mp;
    mp[ans + 1] = INF;

    vector<int> vec;
    int i = n - 1;
    while (len[i] != ans)
        i--;
    for (; i >= 0; i--)
    {
        if (mp[len[i] + 1] > a[i])
        {
            vec.push_back(i);
            mp[len[i]] = max(mp[len[i]], a[i]);
        }
    }
    reverse(vec.begin(), vec.end());
    cout << vec.size() << endl;
    for (int i : vec)
        cout << i + 1 << " ";
    cout << endl;
}

int main()
{
    FASTIO
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}