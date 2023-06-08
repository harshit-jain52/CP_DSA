#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10;
vector<int> g[N];
vector<bool> visited(N, false);

void dfs(int src, vector<int> &v)
{
    v.push_back(src);
    visited[src] = true;

    for (auto child : g[src])
    {
        if (!visited[child])
        {
            dfs(child, v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i;
    cin >> n >> m;
    ll c[n + 1];
    for (i = 1; i <= n; i++)
    {
        cin >> c[i];
    }

    for (i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<vector<int>> comp;
    for (i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            vector<int> v;
            dfs(i, v);
            comp.push_back(v);
        }
    }
    ll cost = 0;
    for (auto vec : comp)
    {
        for (i = 0; i < vec.size(); i++)
        {
            vec[i] = c[vec[i]];
        }
        cost += *min_element(vec.begin(), vec.end());
    }

    cout << cost;
}