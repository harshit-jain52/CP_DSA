#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N = 2e5 + 10;
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

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        bool ans = false;
        reset(n);

        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        ll k = sqrt(n);
        if (k * k != n)
            goto end;

        if (k * (k + 1) != m)
            goto end;

        dfs(1, 0);

        // for (auto vec : allCycles)
        // {
        //     for (int it : vec)
        //     {
        //         cout << it << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        k = sqrt(n);

        if (allCycles.size() != k + 1)
            goto end;

        for (auto vec : allCycles)
        {
            if (vec.size() != k)
                goto end;
        }

        ans = true;

    end:

        cout << ((ans) ? "YES" : "NO") << endl;
    }
}