#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
// Bridge: An edge in directed graph that connects 2 different SCC

const int N = 1e5 + 10;
const int UNVISITED = -1;
vector<int> graph[N];
vector<int> ids(N, UNVISITED);
vector<int> lo(N, INF);
vector<bool> onStack(N, false);
vector<pair<int, int>> bridges;

int id = 1;

void dfs(int v, stack<int> &st)
{
    st.push(v);
    onStack[v] = true;
    ids[v] = lo[v] = id++;

    for (int child : graph[v])
    {
        if (ids[child] == UNVISITED)
            dfs(child, st);

        if (onStack[child])
        {
            lo[v] = min(lo[v], lo[child]);
        }
        else
            bridges.push_back({v, child}); // Bridge
    }

    if (ids[v] == lo[v])
    {
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            onStack[node] = false;
            lo[node] = ids[v];
            if (node == v)
                break;
        }
    }
}