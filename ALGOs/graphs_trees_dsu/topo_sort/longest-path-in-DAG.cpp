#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];
vector<int> indegree, topo;
int n, m;

void create()
{
    indegree.assign(n + 1, 0);

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        indegree[v]++;
    }
}

void kahn()
{
    queue<int> q;

    for (int i = 1; i <= n; i++)
        if (indegree[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int cur_v = q.front();
        q.pop();
        topo.push_back(cur_v);

        for (int next : g[cur_v])
        {
            indegree[next]--;
            if (indegree[next] == 0)
                q.push(next);
        }
    }
}

void longestPath()
{
    if (topo.size() != n) // Cycle detected
    {
        cout << "INFINITE";
        return;
    }

    vector<int> dp(n + 1, 1); // dp[i] = longest path beginning at i
    for (int i = n - 1; i >= 0; i--)
    {
        int cur = topo[i];
        for (int next : g[cur])
            dp[cur] = max(dp[cur], 1 + dp[next]);
    }

    cout << *max_element(dp.begin(), dp.end());
}