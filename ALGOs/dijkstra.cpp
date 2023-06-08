// shortest path in weighted directed graph

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int INF = 1e9 + 10;
vector<pair<int, int>> g[N]; // weighted graph
vector<int> dist(N, INF);
vector<bool> vis(N, false);

void dijkstra(int src)
{
    set<pair<int, int>> st; // weight,node

    st.insert({0, src});
    dist[src] = 0;

    while (st.size() > 0)
    {
        auto node = *st.begin();
        int v = node.second, d = node.first;
        st.erase(st.begin());

        if (vis[v])
            continue;
        
        vis[v] = true;
        for (auto child : g[v])
        {
            int child_v = child.first, wt = child.second;
            if (dist[v] + wt < dist[child_v])
            {
                dist[child_v] = dist[v] + wt;
                st.insert({dist[child_v], child_v});
            }
        }
    }
    // O(V+Elog(V))
}
int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        g[x].push_back({y, wt}); // directed graph
    }
}