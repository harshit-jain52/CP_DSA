#include <bits/stdc++.h>
using namespace std;

/*
Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that
for every directed edge u-v, vertex u comes before v in the ordering
*/

const int N = 1e5 + 10;
vector<int> g[N];
vector<bool> visited;
vector<int> ans;

void dfs(int vertex)
{
    visited[vertex] = true;
    for (int child : g[vertex])
    {
        if (!visited[child])
            dfs(child);
    }
    ans.push_back(vertex);
}

void topological_sort(int n)
{
    visited.assign(n + 1, false);

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}