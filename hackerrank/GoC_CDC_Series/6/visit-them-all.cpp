#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e15;
const int N = 18;

int n, m, all;
ll dist[N][N], dp[N][1 << N];

ll func(int v, int mask)
{
    if (mask == all)
        return dist[v][n - 1];
    if (dp[v][mask] != -1)
        return dp[v][mask];

    ll cost = INF;
    for (int i = 1; i < n - 1; i++)
    {
        if ((mask & (1 << i)) == 0)
        {
            cost = min(cost, dist[v][i] + func(i, mask | (1 << i)));
        }
    }

    return dp[v][mask] = cost;
}

int main()
{
    cin >> n >> m;
    all = (1 << (n - 1)) - 1;

    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dist[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        dist[u][v] = dist[v][u] = w;
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    cout << func(0, 1);
}