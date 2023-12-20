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

ll max_flow(int n, int src, int sink)
{
    ll flow = 0;
    vector<int> level(n + 1, -1);
    vector<int> next(n + 1, 0);

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

    function<ll(int, ll)> dfs = [&](int v, ll curr_flow) -> ll
    {
        if (v == sink)
            return curr_flow;

        int numEdges = adj[v].size();
        for (; next[v] < numEdges; next[v]++)
        {
            int e = adj[v][next[v]];
            ll rem_cap = edges[e].cap - edges[e].flow;
            if (rem_cap > 0 && level[edges[e].to] == level[v] + 1)
            {
                ll bottleNeck = dfs(edges[e].to, min(curr_flow, rem_cap));
                if (bottleNeck > 0)
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
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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
    }

    // int num = 0;
    // for (auto e : edges)
    // {
    //     cout << num++ << "..." << e.from << " " << e.to << " " << e.cap << " " << e.flow << endl;
    // }

    cout << max_flow(n, 1, n);
}