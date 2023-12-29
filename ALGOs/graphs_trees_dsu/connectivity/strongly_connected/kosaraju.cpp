#include <bits/stdc++.h>
using namespace std;

// Find out if a Directed Graph is strongly connected or not
// Strongly Connected: every vertex is reachable from every vertex

const int N = 1e5 + 10;
vector<int> graph[N];
vector<int> rev[N];
vector<bool> vis(N, false);

void dfs1(int v)
{
    vis[v] = true;

    for (auto child : graph[v])
    {
        if (vis[child])
            continue;
        dfs1(child);
    }
}

void dfs2(int v)
{
    vis[v] = true;

    for (auto child : rev[v])
    {
        if (vis[child])
            continue;
        dfs2(child);
    }
}

bool isStronglyConnected()
{
    int n, m;
    cin >> n >> m;

    while (m--)
    {
        int u, v;
        cin >> u >> v; // Directed edge from u to v

        graph[u].push_back(v);
        rev[v].push_back(u);
    }

    dfs1(1); // Forward DFS from arbitrary vertex
    // If any of the vertuces is unvisited, return false

    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == false)
            return false;

        vis[i] = false;
    }

    dfs2(1); // Reverse DFS from the same vertex
    // If any of the vertuces is unvisited, return false

    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == false)
            return false;
    }

    return true;
}