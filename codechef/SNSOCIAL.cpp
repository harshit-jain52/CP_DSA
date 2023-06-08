#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 500;
int lvl[N][N];
bool vis[N][N];
int n, m;

void reset()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            lvl[i][j] = vis[i][j] = 0;
        }
    }
}

vector<pair<int, int>> neighbours = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

void bfs(vector<pair<int, int>> &src)
{
    queue<pair<int, int>> q;
    for (auto it : src)
    {
        q.push(it);
        vis[it.first][it.second] = 1;
    }

    while (!q.empty())
    {
        int cur_x = q.front().first, cur_y = q.front().second;
        q.pop();

        for (auto nb : neighbours)
        {
            int x = cur_x + nb.first, y = cur_y + nb.second;
            if (x < 0 || y < 0 || x >= n || y >= m)
                continue;

            if (!vis[x][y])
            {
                q.push({x, y});
                vis[x][y] = 1;
                lvl[x][y] = lvl[cur_x][cur_y] + 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        reset();

        cin >> n >> m;
        int a[n][m];
        int maxvalue = 0;
        vector<pair<int, int>> sources;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
                if (a[i][j] > maxvalue)
                {
                    maxvalue = a[i][j];
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == maxvalue)
                {
                    sources.push_back({i, j});
                }
            }
        }

        bfs(sources);

        int maxlvl = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (lvl[i][j] > maxlvl)
                {
                    maxlvl = lvl[i][j];
                }
            }
        }

        cout << maxlvl << endl;
    }
}