#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 2e5 + 10;
vector<pair<int, int>> g[N];
vector<bool> seen(N, false);
vector<int> path;

void dfs(int v)
{
    while (!g[v].empty())
    {
        auto [child, edgeNum] = g[v].back();
        g[v].pop_back(); // remove edge

        if (seen[edgeNum])
            continue;

        seen[edgeNum] = true;
        dfs(child);
    }
    path.push_back(v);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> degree(n + 1, 0);

    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back({b, i});
        g[b].push_back({a, i});

        degree[a]++;
        degree[b]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (degree[i] % 2 != 0)
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    dfs(1);

    if (path.size() != m + 1)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    
    for (int v : path)
    {
        cout << v << " ";
    }
}