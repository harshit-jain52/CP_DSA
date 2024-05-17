#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;
vector<int> subTreeSz;
vector<int> centroids;

void dfs(int v, int pp)
{
    subTreeSz[v] = 1;
    for (auto ch : g[v])
    {
        if (ch == pp)
            continue;

        dfs(ch, v);
        subTreeSz[v] += subTreeSz[ch];
    }

    bool isCentroid = true;
    for (auto ch : g[v])
    {
        if (ch != pp)
        {
            if (2 * subTreeSz[ch] > n)
                isCentroid = false;
        }
    }
    if (2 * (n - subTreeSz[v]) > n)
        isCentroid = false;

    if (isCentroid)
        centroids.push_back(v);
}

void solve()
{
    cin >> n;
    g.resize(n + 1);
    subTreeSz.resize(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // Find centroids
    dfs(1, 0);
}