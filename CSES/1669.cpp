#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

const int N = 1e5 + 10;
vector<int> g[N];
int color[N];
int par[N];
vector<vector<int>> allCycles;

void reset(int n)
{
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        color[i] = 0;
        par[i] = 0;
    }
    allCycles.clear();
}

void dfs(int v, int p)
{
    if (allCycles.size() > 0)
        return;
        
    if (color[v] == 2)
        return;

    if (color[v] == 1)
    {
        vector<int> cycle;

        int cur = p;
        cycle.push_back(cur);

        while (cur != v)
        {
            cur = par[cur];
            cycle.push_back(cur);
        }
        if (cycle.size() >= 3)
            allCycles.push_back(cycle);

        return;
    }

    par[v] = p;
    color[v] = 1;

    for (int child : g[v])
    {
        if (child == par[v])
            continue;

        dfs(child, v);
    }

    color[v] = 2;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    reset(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 0)
            dfs(i, 0);
    }

    bool isPossible = false;

    if (allCycles.size() > 0)
    {
        auto cycle = allCycles[0];
        isPossible = true;
        cout << cycle.size() + 1 << endl;
        for (int city : cycle)
            cout << city << " ";

        cout << cycle[0];
    }

    if (!isPossible)
        cout << "IMPOSSIBLE";
}