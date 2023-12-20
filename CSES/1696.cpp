#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N = 1002;
vector<int> adj[N];

struct Edge
{
    int to, from;
    int cap, flow = 0;
    Edge(int u, int v, ll c) : from(u), to(v), cap(c) {}
};

vector<Edge> edges;
int idx = 0;

int max_flow(int n, int src, int sink)
{
    int flow = 0;
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

    function<int(int, int)> dfs = [&](int v, int curr_flow) -> int
    {
        if (v == sink)
            return curr_flow;

        int numEdges = adj[v].size();
        for (; next[v] < numEdges; next[v]++)
        {
            int e = adj[v][next[v]];
            int rem_cap = edges[e].cap - edges[e].flow;
            if (rem_cap > 0 && level[edges[e].to] == level[v] + 1)
            {
                int bottleNeck = dfs(edges[e].to, min(curr_flow, rem_cap));
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
        while (int f = dfs(src, INT_MAX))
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

    int n, m, k;
    cin >> n >> m >> k;

    while (k--)
    {
        int a, b;
        cin >> a >> b;

        edges.emplace_back(a, b + n, 1);
        adj[a].push_back(idx++);
        edges.emplace_back(b + n, a, 0);
        adj[b + n].push_back(idx++);
    }

    for (int i = 1; i <= n; i++) // Link to Source
    {
        edges.emplace_back(0, i, 1);
        adj[0].push_back(idx++);
        edges.emplace_back(i, 0, 0);
        adj[i].push_back(idx++);
    }

    for (int i = 1; i <= m; i++) // Link to Sink
    {
        edges.emplace_back(i + n, n + m + 1, 1);
        adj[i + n].push_back(idx++);
        edges.emplace_back(n + m + 1, i + n, 0);
        adj[n + m + 1].push_back(idx++);
    }

    cout << max_flow(n + m + 1, 0, n + m + 1) << endl;

    for (int i = 1; i <= n; i++)
    {
        for (int e : adj[i])
        {
            if (edges[e].flow == 1)
            {
                cout << i << " " << edges[e].to - n << endl;
                continue;
            }
        }
    }
}