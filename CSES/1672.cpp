#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const ll INF = 1e15 + 10;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;

    ll dist[n + 5][n + 5];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    while (m--)
    {
        int a, b;
        ll c;

        cin >> a >> b >> c;
        dist[a][b] = dist[b][a] = min(dist[a][b], c);
    }

    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    while (q--)
    {
        int a, b;
        cin >> a >> b;

        if (dist[a][b] == INF)
            cout << -1;
        else
            cout << dist[a][b];

        cout << endl;
    }
}