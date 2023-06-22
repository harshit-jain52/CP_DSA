#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;
const int N = 2e5 + 10;

vector<int> g[N];
bool visited[N];
ll leaves[N];

void reset(int n)
{
    for (int i = 1; i <= n; i++)
    {
        visited[i] = false;
        g[i].clear();
        leaves[i] = 0;
    }
}

void dfs(int vertex)
{
    visited[vertex] = true;

    if (g[vertex].size() == 1 && vertex != 1)
        leaves[vertex] = 1;

    else
    {
        for (auto child : g[vertex])
        {
            if (visited[child])
                continue;

            dfs(child);
            leaves[vertex] += leaves[child];
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        reset(n);

        for (int i = 0; i < n-1; i++)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1);

        int q;
        cin >> q;
        while (q--)
        {
            int x, y;
            cin >> x >> y;
            cout << leaves[x] * leaves[y] << endl;
        }
    }
}