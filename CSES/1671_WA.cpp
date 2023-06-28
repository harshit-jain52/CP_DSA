// shortest path in weighted directed graph

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10;
const ll INF = 1e15 + 10;
vector<pair<int, ll>> g[N];
vector<ll> dist(N, INF);
vector<bool> vis(N, false);

void dijkstra(int src)
{
    set<pair<int, int>> st;

    st.insert({0, src});
    dist[src] = 0;

    while (st.size() > 0)
    {
        auto node = *st.begin();
        int v = node.second;
        ll d = node.first;
        st.erase(st.begin());

        if (vis[v])
            continue;

        vis[v] = true;
        for (auto child : g[v])
        {
            int child_v = child.first;
            ll wt = child.second;
            if (dist[v] + wt < dist[child_v])
            {
                dist[child_v] = dist[v] + wt;
                st.insert({dist[child_v], child_v});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        ll wt;
        cin >> x >> y >> wt;
        g[x].push_back({y, wt});
    }

    dijkstra(1);

    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
}