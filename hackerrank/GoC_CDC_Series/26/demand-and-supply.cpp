#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int N = 2e5 + 5;

vector<int> g[N];
ll s[N], d[N], tot;

void reset(int n)
{
    tot = 0;
    for (int i = 0; i <= n; i++)
        g[i].clear();
}

ll dfs(int v, int par)
{
    ll diff = d[v] - s[v];
    ll req = 0;

    for (auto ch : g[v])
    {
        if (ch == par)
            continue;
        ll tmp = dfs(ch, v);
        tot += abs(tmp);
        req += tmp;
    }

    return (req + diff);
}

void solve()
{
    int n;
    cin >> n;
    reset(n);
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    for (int i = 1; i <= n; i++)
        cin >> s[i];

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0);
    cout << tot << endl;
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