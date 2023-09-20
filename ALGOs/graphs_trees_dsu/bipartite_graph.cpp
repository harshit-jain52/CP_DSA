#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
/*
Bipartite graph: its nodes can be colored using two colors so that there are
no adjacent nodes with the same colo
*/

vector<int> g[N];
bool vis[N];
vector<int> group(N, -1);
bool is_bipartite = true;

void dfs(int v, bool color)
{
    vis[v] = true;
    group[v] = color;

    for (auto child : g[v])
    {
        if (vis[child])
            is_bipartite &= (group[child] != color);
        else
            dfs(child, !color);
    }
}

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    group[src] = 0;
    while (!q.empty())
    {
        int cur_v = q.front();
        q.pop();
        for (int child : g[cur_v])
        {
            if (group[child] == -1)
            {
                group[child] = group[cur_v] ^ 1;
                q.push(child);
            }
            else
                is_bipartite &= (group[child] != group[cur_v]);
        }
    }
}

int main()
{
    int n;

    // DFS solution
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i, 0);
    }

    // BFS Solution
    for (int i = 1; i <= n; i++)
    {
        if (group[i] == -1)
            bfs(i);
    }
}