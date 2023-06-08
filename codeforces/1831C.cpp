#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
vector<int> g[N];
map<pair<int, int>, int> idx;
bool visited[N];
int activate[N];
int ct[N];

void dfs(int vertex)
{
    visited[vertex] = true;
    for (auto child : g[vertex])
    {
        if (visited[child])
            continue;

        int i = idx[{vertex, child}];
        activate[child] = i;
        if (i >= activate[vertex])
        {
            ct[child] = ct[vertex];
        }
        else
        {
            ct[child] = ct[vertex] + 1;
        }

        dfs(child);
    }
}

void reset(int n)
{
    for (int i = 1; i <= n; i++)
    {
        visited[i] = false;
        activate[i] = -1;
        g[i].clear();
        ct[i] = 1;
    }
    idx.clear();
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        reset(n);

        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
            idx[{u, v}] = i;
            idx[{v, u}] = i;
        }

        activate[1] = 0;
        dfs(1);

        // for (int i = 1; i <= n; i++)
        // {
        //     cout << activate[i] << " ";
        // }

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans = max(ans, ct[i]);
        }

        cout << ans << endl;
    }
}