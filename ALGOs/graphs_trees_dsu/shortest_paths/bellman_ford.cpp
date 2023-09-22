// single source shortest path in weighted directed graph
// can handle negative weights and detect negative cycles

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 10;

typedef struct
{
    int u;
    int v;
    int wt;
} edge;

// RELAX all the edges N-1 times sequentially
// Relaxation : if(dist[u] + wt < dist[v]) change dist[v]

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> dist(n + 1, INF);
    edge e[m];

    for (int i = 0; i < m; i++)
        cin >> e[i].u >> e[i].v >> e[i].wt;

    int src = 1; // intialize source
    dist[src] = 0;

    int ct = n - 1;

    while (ct--)
    {
        for (int i = 0; i < m; i++)
        {
            if (dist[e[i].u] != INF) // handle negative weight
                dist[e[i].v] = min(dist[e[i].v], dist[e[i].u] + e[i].wt);
        }
    }
    // O(V*E)

    // Detect negative cycle: on Nth iteration, if value(s) in dist reduce 
}
