#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N = 501;
ll graph[N][N];

ll max_flow(int n, int src, int sink)
{
    ll flow = 0;
    vector<int> parent(n + 1, -1);

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

    while (reachable())
    {
        int node = sink;
        ll min_cap = LLONG_MAX;
        while (node != src)
        {
            min_cap = min(min_cap, graph[parent[node]][node]);
            node = parent[node];
        }

        node = sink;
        while (node != src)
        {
            graph[parent[node]][node] -= min_cap;
            graph[node][parent[node]] += min_cap;
            node = parent[node];
        }

        flow += min_cap;
        fill(parent.begin(), parent.end(), -1);
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
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] += c;
    }

    cout << max_flow(n, 1, n);
}