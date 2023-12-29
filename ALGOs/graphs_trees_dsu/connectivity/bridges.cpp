#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
/*
Bridge: an edge whose removal increases the no. of connected components of the graph G

the condition for UV to be a bridge is:
disc[U] < low[V] instead of disc[U] <= low[V]
*/

const int N = 1e5 + 10;
int Time;
vector<int> graph[N];
vector<int> disc(N, 0);  // discovery time during DFS traversal
vector<int> low(N, INF); // lowest discovery time of node
vector<pair<int, int>> br;

void dfsBR(int u, int par)
{
    disc[u] = low[u] = ++Time;
    for (int v : graph[u])
    {
        if (v == par)
            continue;

        if (!disc[v])
        {
            dfsBR(v, u);

            if (disc[u] < low[v])
                br.push_back({u, v});

            low[u] = min(low[u], low[v]);
        }
        else
            low[u] = min(low[u], disc[v]);
    }
}

void BR(int n)
{
    Time = 0;
    for (int i = 1; i <= n; i++)
        if (!disc[i])
            dfsBR(i, i);
}