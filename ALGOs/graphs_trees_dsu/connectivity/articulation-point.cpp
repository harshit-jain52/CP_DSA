#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
/*
Articulation Point: a vertex whose removal increases the no. of connected components of the graph G

two conditions for U to be an AP:
1. If all paths from A (an ancestor of U) to V require U to be in the graph.
    (i) U is an articulation point if it does not have an adjacent node V that can reach A without requiring U to be in G.
        (disc[u]<low[v])
    (ii) U is an articulation point if it is the root of some cycle in the DFS traversal.
        (disc[u]=low[v])
2. If U is the root of the DFS traversal with at least 2 children subgraphs disconnected from each other.

For every node U we have to find the node V with the least discovery time that can be reached from U
following some DFS traversal path which does not require to pass through any already visited nodes
*/

const int N = 1e5 + 10;
int Time;
vector<int> graph[N];
vector<int> disc(N, 0);  // discovery time during DFS traversal
vector<int> low(N, INF); // lowest discovery time of node
vector<bool> ap(N, false);

int dfsAP(int u, int par)
{
    int children = 0;
    disc[u] = low[u] = ++Time;
    for (int v : graph[u])
    {
        if (v == par)
            continue;

        if (!disc[v])
        {
            children++;
            dfsAP(v, u);

            if (disc[u] <= low[v])
                ap[u] = true;

            low[u] = min(low[u], low[v]);
        }
        else
            low[u] = min(low[u], disc[v]);
    }

    return children;
}

void AP(int n)
{
    Time = 0;
    for (int i = 1; i <= n; i++)
        if (!disc[i])
            ap[i] = (dfsAP(i, i) > 1);
}