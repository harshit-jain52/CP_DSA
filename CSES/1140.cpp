#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<pair<pair<int, int>, ll>> abp(n);
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> abp[i].first.first >> abp[i].first.second >> abp[i].second;
        v.push_back(abp[i].first.first);
        v.push_back(abp[i].first.second + 1);
    }

    // Coordinate Compression
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    map<int, int> comp;
    int idx = 0;
    for (auto it : v)
        comp[it] = idx++;

    int len = idx;
    vector<vector<pair<int, ll>>> project(len);
    for (auto it : abp)
    {
        project[comp[it.first.first]].push_back({comp[it.first.second + 1], it.second});
    }

    vector<ll> dp(len, 0);
    for (int i = len - 1; i >= 0; i--)
    {
        if (i < len - 1)
            dp[i] = dp[i + 1];

        for (auto it : project[i])
        {
            dp[i] = max(dp[i], it.second + dp[it.first]);
        }
    }

    cout << dp[0];
}