#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N = 501;
vector<int> adj[N];

struct Edge
{
    int to, from;
    ll cap, flow = 0;
    Edge(int u, int v, ll c) : from(u), to(v), cap(c) {}
};

vector<Edge> edges;
int idx = 0;

ll max_flow(int n, int src, int sink) // Dinic's Algorithm
{
    ll flow = 0;
    vector<int> level(n + 1, -1);
    vector<int> next(n + 1, 0);

    // Construct level graph (layered network)
    function<bool()> bfs = [&]() -> bool
    {
        queue<int> q;
        q.push(src);
        level[src] = 0;

        while (!q.empty())
        {
            int cur_v = q.front();
            q.pop();

            for (int e : adj[cur_v])
            {
                if (edges[e].cap - edges[e].flow <= 0 || level[edges[e].to] != -1)
                    continue;

                level[edges[e].to] = level[cur_v] + 1;
                q.push(edges[e].to);
            }
        }

        return level[sink] != -1;
    };

    // Using only valid edges in the level graph, do multiple DFSs src->sink until a blocking flow is reached
    // Blocking flow: can't find path src->sink 'cause too many edges are saturated
    function<ll(int, ll)> dfs = [&](int v, ll curr_flow) -> ll
    {
        if (v == sink)
            return curr_flow;

        int numEdges = adj[v].size();
        for (; next[v] < numEdges; next[v]++) // Shimon-Alan Optimization: pruning dead ends
        {
            int e = adj[v][next[v]];
            ll rem_cap = edges[e].cap - edges[e].flow;
            if (rem_cap > 0 && level[edges[e].to] == level[v] + 1)
            {
                ll bottleNeck = dfs(edges[e].to, min(curr_flow, rem_cap));
                if (bottleNeck > 0) // Augmenting path, not a Dead End
                {
                    edges[e].flow += bottleNeck;
                    edges[e ^ 1].flow -= bottleNeck;
                    return bottleNeck;
                }
            }
        }
        return 0;
    };

    while (bfs())
    {
        while (ll f = dfs(src, LLONG_MAX))
        {
            flow += f;
        }
        fill(next.begin(), next.end(), 0);
        fill(level.begin(), level.end(), -1);
    }

    return flow;
    // TC: O(E*V^2)
}

int main()
{
    int n, m;
    cin >> n >> m;

    while (m--)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        edges.emplace_back(a, b, c);
        adj[a].push_back(idx++);
        edges.emplace_back(b, a, 0LL);
        adj[b].push_back(idx++);
        // Edges are indexed in such a way that idx = idx^1 gives actual-edge<-->back-edge
    }

    cout << max_flow(n, 1, n);
}