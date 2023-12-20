#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N = 501;
ll graph[N][N]; // Flow Capacities

ll max_flow(int n, int src, int sink) // Ford-Fulkerson Algorithm
{
    ll flow = 0;
    vector<int> parent(n + 1, -1);

    // Find a path from src to sink with positive capacities (use BFS; Edmonds-Karp Algorithm)
    auto reachable = [&]() -> bool
    {
        queue<int> q;
        q.push(src);

        while (!q.empty())
        {
            int cur_v = q.front();
            q.pop();
            for (int child = 1; child <= n; child++)
            {
                ll cap = graph[cur_v][child];
                if (cap <= 0 || parent[child] != -1)
                    continue;
                parent[child] = cur_v;
                q.push(child);
            }
        }

        return parent[sink] != -1;
    };

    while (reachable()) // Keep increasing flow until the sink is unreachable
    {
        int node = sink;
        ll curr_flow = LLONG_MAX; // Min capacity in the found path (bottleneck value)
        while (node != src)
        {
            curr_flow = min(curr_flow, graph[parent[node]][node]);
            node = parent[node];
        }

        node = sink;
        while (node != src)
        {
            graph[parent[node]][node] -= curr_flow; // Subtract from each edge of the path
            graph[node][parent[node]] += curr_flow; // Add to each back edge
            node = parent[node];
        }

        flow += curr_flow;
        fill(parent.begin(), parent.end(), -1);
    }

    return flow;
    // TC: O(V*E^2)
}

int main()
{
    int n, m;
    cin >> n >> m;

    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] += c;
    }

    cout << max_flow(n, 1, n);
}