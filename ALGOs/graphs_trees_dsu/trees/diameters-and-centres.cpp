#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;
vector<int> dis, par;

void dfs(int v, int pp, int dd)
{
    dis[v] = dd;
    par[v] = pp;

    for (auto ch : g[v])
    {
        if (ch != pp)
            dfs(ch, v, dd + 1);
    }
}

void solve()
{
    cin >> n;
    g.resize(n + 1);
    dis.resize(n + 1);
    par.resize(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // Find a diameter

    dfs(1, 0, 0);
    int end1 = 1;
    for (int i = 2; i <= n; i++)
    {
        if (dis[end1] < dis[i])
            end1 = i;
    }

    dfs(end1, 0, 0);
    int end2 = 1;
    for (int i = 2; i <= n; i++)
    {
        if (dis[end2] < dis[i])
            end2 = i;
    }

    vector<int> path;
    int curr = end2;
    while (curr != 0)
    {
        path.push_back(curr);
        curr = par[curr];
    }

    int diam = path.size() - 1;

    // Centre(s) and No. of diameters
    if (diam % 2 == 0) // 1 centre
    {
        int centre = path[path.size() / 2];
        // find no. of nodes at dist diam/2 in each subtree
        // no. of diam = sum of pair of products
    }
    else // 2 centres
    {
        int centre1 = path[path.size() / 2];
        int centre2 = path[(path.size() - 1) / 2];
        // from each centre, with other centre as parent, find no. of nodes at dist diam/2
        // no. of diam = product
    }
}