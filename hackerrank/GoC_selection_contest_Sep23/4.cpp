#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;
const ll INF = 1e15;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<ll, ll>> v(n);

        for (int i = 0; i < n; i++)
        {
            cin >> v[i].second;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> v[i].first;
        }

        sort(v.begin(), v.end());

        // for (auto it : v)
        // {
        //     cout << it.first << " ";
        // }
        // cout << endl;
        // for (auto it : v)
        // {
        //     cout << it.second << " ";
        // }
        // cout << endl;

        vector<ll> dp(n + 1, INF);
        dp[0] = -INF;

        for (int i = 0; i < n; i++)
        {
            int l = (int)(upper_bound(dp.begin(), dp.end(), v[i].second) - dp.begin());
            dp[l] = v[i].second;
        }

        // for (auto it : dp)
        // {
        //     cout << it << " ";
        // }        
        // cout << endl;

        cout << (int)(lower_bound(dp.begin(), dp.end(), INF) - dp.begin()) - 1 << endl;
    }
}