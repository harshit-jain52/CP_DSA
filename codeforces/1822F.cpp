#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(int vertex, int parent, vector<int> g[], vector<int> &depth)
{
    for (int child : g[vertex])
    {
        if (child == parent)
            continue;

        depth[child] = depth[vertex] + 1;
        dfs(child, vertex, g, depth);
    }
}

void findParents(int vertex, int parent, vector<int> g[], vector<int> &par)
{
    par[vertex] = parent;
    for (int child : g[vertex])
    {
        if (child == parent)
            continue;

        findParents(child, vertex, g, par);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        ll k, c, maxprofit = 0;
        cin >> n >> k >> c;

        vector<int> g[n + 1];
        vector<int> depth1(n + 1, 0);

        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        int root = 1, maxdepth = -1, node1;
        dfs(root, -1, g, depth1);

        for (int i = 1; i <= n; i++)
        {
            if (depth1[i] > maxdepth)
            {
                maxdepth = depth1[i];
                node1 = i;
            }
        }

        maxprofit = max(maxprofit, k * maxdepth);

        if (c >= k)
        {
            cout << maxprofit;
        }
        else
        {
            vector<int> depth2(n + 1, 0);
            dfs(node1, -1, g, depth2);

            for (int i = 1; i <= n; i++)
            {
                maxprofit = max(maxprofit, k * depth2[i] - c * min(depth1[node1], depth1[i]));
            }
            cout << maxprofit;
        }
        cout << endl;
    }
}