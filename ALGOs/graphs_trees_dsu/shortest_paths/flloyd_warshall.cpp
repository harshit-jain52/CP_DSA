// all pair shortest paths
// can handle negative weights, but not negative cycles

#include <bits/stdc++.h>
using namespace std;
const int N = 510;
const int INF = 1e7 + 10;

int dist[N][N];
int par[N][N]; // for printing shortest path

void printPath(int i, int j)
{
    if (i != j)
        printPath(i, par[i][j]);
    cout << j << " ";
}

int main()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dist[i][j] = INF;
            par[i][j] = i;
        }
    }

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        dist[x][y] = wt;
    }

    // d[i][j] at kth level = d[i][k]+d[k][j]
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF) // handle negative weights
                {
                    if (dist[i][j] < dist[i][k] + dist[k][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        par[i][j] = par[k][j];
                    }
                }
            }
        }
    }

    // O(V^3)

    // Finding Length of Shortest Cycle
    int len = INF;
    for (int i = 1; i <= n; i++)
        len = min(len, dist[i][i]);

    // Negative Cycle Detection
    if (len < 0)
        cout << "Negative Cycle Detected\n";

    // Diameter of Graph -> longest shortest path
    int diameter = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            diameter = max(diameter, dist[i][j]);
}