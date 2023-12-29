#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
// Find out strongly connected components in a directed graph

const int N = 1e5 + 10;
const int UNVISITED = -1;
vector<int> graph[N];
vector<int> ids(N, UNVISITED);
vector<int> lo(N, INF); // Low-Link Value of a node: smallest id reachable from that node (including itself) in a DFS traversal
vector<bool> onStack(N, false);
int id = 1;

// Low-link values depend highly on how the traversal is carried out, but SCCs of a graph are unique
// Tarjan's Algo maintains a stack on valid nodes from which to update low-link values from
// Result: All nodes belonging to a SCC have same low-link value, which is different from any node of any other SCC

void dfs(int v, stack<int> &st)
{
    st.push(v);
    onStack[v] = true;
    ids[v] = lo[v] = id++;

    for (int child : graph[v])
    {
        if (ids[child] == UNVISITED)
            dfs(child, st);

        if (onStack[child]) // min low-link on callback
            lo[v] = min(lo[v], lo[child]);
    }

    if (ids[v] == lo[v]) // Marks the start of SCC
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