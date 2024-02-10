#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int N = 2e5 + 10;
const ll INF = 1e15;
vector<pair<int, ll>> graph[N];
vector<ll> dist(N, INF);
vector<bool> vis(N, false);

void dijkstra(int src)
{
    set<pair<ll, int>> st;

    st.insert({0, src});
    dist[src] = 0;

    while (st.size() > 0)
    {
        auto node = *st.begin();
        int v = node.second;
        st.erase(st.begin());

        if (vis[v])
            continue;

        vis[v] = true;
        for (auto child : graph[v])
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
    FASTIO
    int n;
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        int a, b, x;
        cin >> a >> b >> x;
        graph[i].push_back({i + 1, a});
        graph[i].push_back({x, b});
    }

    dijkstra(1);

    cout << dist[n];
}