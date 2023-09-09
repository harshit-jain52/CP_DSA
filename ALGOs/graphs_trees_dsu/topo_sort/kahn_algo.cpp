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
    queue<int> q;

    for (int i = 1; i <= n; i++)
    { // locate the nodes with indegree 0 and push them into the queue
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int cur_v = q.front();
        q.pop();

        // add the current node to the order
        order.push_back(cur_v);

        for (int next : g[cur_v])
        {
            // remove the current node from the graph
            indegree[next]--;

            // push any new nodes with indegree 0 into the queue
            if (indegree[next] == 0)
                q.push(next);
        }
    }
}
