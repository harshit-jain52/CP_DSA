#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;
const int N = 105;
vector<int> g[N];
vector<bool> visited(N, false);
ll cost[N][N];

ll dfs(int vertex)
{
    ll ans = 0;
    visited[vertex] = true;

    if (g[vertex].size() == 1 && vertex != 0)
        return 0;
    
    for (auto child : g[vertex])
    {
        if (visited[child])
            continue;

        ans = max(ans, cost[vertex][child] + dfs(child));
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back(v);
        g[v].push_back(u);
        cost[u][v] = cost[v][u] = c;
    }

    cout << dfs(0);
}