#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define F first
#define S second
typedef long long ll;
const int M = 1e9 + 7;
const int N = 1002;
const ll INF = 1e15;

vector<pair<int, ll>> g[N];
int s[N];
ll dist[N][N];

void reset(int n)
{
    for (int i = 0; i <= n; i++)
    {
        g[i].clear();
        for (int j = 0; j < N; j++)
            dist[i][j] = INF;
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    reset(n);
    while (m--)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }

    dist[1][s[1]] = 0;
    priority_queue<pair<ll, pair<int, int>>> pq;
    pq.push({0, {1, s[1]}});

    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();

        int v = cur.S.F, slow = cur.S.S;
        int nslo = min(slow, s[v]);
        for (auto next : g[v])
        {
            int nv = next.F;
            ll wt = next.S;
            if (dist[nv][nslo] > dist[v][slow] + wt * nslo)
            {
                dist[nv][nslo] = dist[v][slow] + wt * nslo;
                pq.push({-dist[nv][nslo], {nv, nslo}});
            }
        }
    }

    ll ans = INF;
    for (int i = 0; i < N; i++)
        ans = min(ans, dist[n][i]);
    cout << ans << endl;
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