#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

const int N = 1e5 + 10;
vector<int> g[N];
ll dp[N];

ll func(int vertex)
{
    if (dp[vertex] != -1)
        return dp[vertex];

    ll ans = 0;
    for (auto it : g[vertex])
    {
        ans = max(ans, 1 + func(it));
    }

    return dp[vertex] = ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof(dp));

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, func(i));
    }
    cout << ans;
}