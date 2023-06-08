#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
ll a[1010][1010];
bool vis[1010][1010];
ll sum;

void dfs(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= m)
    {
        return;
    }
    if (vis[x][y] || a[x][y]==0)
    {
        return;
    }

    sum += a[x][y];
    vis[x][y] = true;

    dfs(x - 1, y);
    dfs(x + 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
                vis[i][j] = false;
            }
        }

        ll maxsum = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j])
                {
                    sum = 0;
                    dfs(i, j);
                    maxsum = max(maxsum, sum);
                }
            }
        }

        cout << maxsum << endl;
    }
}