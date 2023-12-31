#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int INF = 1e9;
const int M = 998244353;
const int N = 1e3 + 5;

int binExp(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * 1LL * a) % M;
        }
        a = (a * 1LL * a) % M;
        b = b >> 1;
    }
    return ans;
}

char grid[N][N];
int disc[N][N];
int low[N][N];
int ap[N][N];
int Time;
vector<pair<int, int>> edges{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool check(int x, int y, int h, int w)
{
    if (x < 0 || y < 0 || x >= h || y >= w)
        return false;
    if (grid[x][y] == '.')
        return false;

    return true;
}

int dfs(int x, int y, int parx, int pary, int h, int w)
{
    int children = 0;
    disc[x][y] = low[x][y] = ++Time;

    for (auto [dx, dy] : edges)
    {
        int x_next = x + dx;
        int y_next = y + dy;
        if (!check(x_next, y_next, h, w))
            continue;
        if (x_next == parx && y_next == pary)
            continue;

        if (!disc[x_next][y_next])
        {
            children++;
            dfs(x_next, y_next, x, y, h, w);

            if (disc[x][y] <= low[x_next][y_next])
                ap[x][y]++;

            low[x][y] = min(low[x][y], low[x_next][y_next]);
        }
        else
            low[x][y] = min(low[x][y], disc[x_next][y_next]);
    }

    return children;
}

int main()
{
    FASTIO
    int h, w;
    cin >> h >> w;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> grid[i][j];
            disc[i][j] = 0;
            low[i][j] = INF;
            ap[i][j] = 0;
        }
    }

    Time = 0;
    int comp = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (grid[i][j] == '.' || disc[i][j] != 0)
                continue;
            ap[i][j] = dfs(i, j, i, j, h, w) - 1;
            comp++;
        }
    }

    int e = 0;
    int ct = 0;
    // cout << comp << endl;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (grid[i][j] == '.')
                continue;

            ct++;
            // cout << i << "," << j << " " << ap[i][j] << endl;
            e = (e + (comp + ap[i][j])) % M;
        }
    }
    cout << (e * 1LL * binExp(ct, M - 2)) % M;
}