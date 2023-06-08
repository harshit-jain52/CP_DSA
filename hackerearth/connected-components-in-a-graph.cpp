/*
https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];

bool visited[N];

void dfs(int vertex)
{
    visited[vertex] = true;
    for (int child : g[vertex])
    {
        if (visited[child])
            continue;
        dfs(child);
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ct = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            ct++;
            dfs(i);
        }
    }

    cout << ct;
}