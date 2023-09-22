#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e15 + 10;

typedef struct
{
    int u;
    int v;
    ll wt;
} edge;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<ll> dist(n + 1, INF);
    vector<bool> connected(n + 1, false);
    edge e[m];

    for (int i = 0; i < m; i++)
    {
        ll x;
        cin >> e[i].u >> e[i].v >> x;
        e[i].wt = -x;
    }

    dist[1] = 0;
    connected[n] = true;

    int ct = n - 1;

    while (ct--)
    {
        for (int i = 0; i < m; i++)
        {
            if (dist[e[i].u] != INF)
                dist[e[i].v] = min(dist[e[i].v], dist[e[i].u] + e[i].wt);

            if (connected[e[i].v])
                connected[e[i].u] = true;
        }
    }

    bool scoreExists = true;

    for (int i = 0; i < m; i++)
    {
        if (dist[e[i].u] != INF && dist[e[i].u] + e[i].wt < dist[e[i].v] && connected[e[i].v])
        {
            scoreExists = false;
            break;
        }
    }

    if (scoreExists)
        cout << -dist[n];
    else
        cout << -1;
}
