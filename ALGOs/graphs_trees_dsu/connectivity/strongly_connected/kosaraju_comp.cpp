#include <bits/stdc++.h>
using namespace std;

// Find out strongly connected components in a directed graph

const int N = 1e5 + 10;
vector<int> g[N], rg[N];
vector<bool> vis(N, false), rvis(N, false);
vector<int> topo;

void dfs(int v)
{
    vis[v] = true;

    for (int u : g[v])
    {
        if (!vis[u])
            dfs(u);
    }

    topo.push_back(v);
}

int c = 0, comp[N];

void rdfs(int v)
{
    rvis[v] = true;
    comp[v] = c;

    for (int u : rg[v])
    {
        if (!rvis[u])
            rdfs(u);
    }
}

int main()
{
    int n;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i);
    }

    reverse(topo.begin(), topo.end());

    for (int i : topo)
    {
        if (!rvis[i])
        {
            c++;
            rdfs(i);
        }
    }
}

// SCC of a graph form a DAG