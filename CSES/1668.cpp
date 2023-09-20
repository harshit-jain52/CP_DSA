#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 1e5 + 10;
vector<int> g[N];
bool vis[N];
int team[N];
bool is_bipartite = true;

void reset(int n)
{
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        vis[i] = false;
        team[i] = -1;
    }
}

void dfs(int v, bool color)
{
    vis[v] = true;
    team[v] = color;

    for (auto child : g[v])
    {
        if (vis[child])
            is_bipartite &= (team[child] != color);
        else
            dfs(child, !color);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    reset(n);

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i, 0);
    }

    if (!is_bipartite)
        cout << "IMPOSSIBLE";
    else
    {
        for (int i = 1; i <= n; i++)
        {
            cout << team[i] + 1 << " ";
        }
    }
}