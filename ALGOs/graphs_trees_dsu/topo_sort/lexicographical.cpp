#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];
vector<int> indegree;
vector<int> order;

void create(int n, int m)
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

void kahn(int n)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
            pq.push(i);
    }

    while (!pq.empty())
    {
        int cur_v = pq.top();
        pq.pop();

        order.push_back(cur_v);

        for (int next : g[cur_v])
        {
            indegree[next]--;

            if (indegree[next] == 0)
                pq.push(next);
        }
    }
}
