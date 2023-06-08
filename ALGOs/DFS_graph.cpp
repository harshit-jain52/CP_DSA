#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];

bool visited[N];

void dfs(int vertex)
{
    // take action on vertex after entering the vertex
    visited[vertex] = true;
    for (int child : g[vertex])
    {
        // take action on child before entering the child node
        if (visited[child])
            continue;
        dfs(child);

        // take action on child after exiting child node
    }

    // take action on vertex before exiting the vertex

    // Time Complexity O(V+E)
}

int main()
{
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
}