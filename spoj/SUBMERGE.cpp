#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int N = 1e5 + 10;
int Time;
vector<int> graph[N];
vector<int> disc(N, 0);
vector<int> low(N, INF);
vector<bool> ap(N, false);

int dfsAP(int v, int par)
{
    int children = 0;
    disc[v] = low[v] = ++Time;
    for (int child : graph[v])
    {
        if (child == par)
            continue;

        if (!disc[child])
        {
            children++;
            dfsAP(child, v);

            if (disc[v] <= low[child])
                ap[v] = true;

            low[v] = min(low[v], low[child]);
        }
        else
            low[v] = min(low[v], disc[child]);
    }

    return children;
}

void reset(int n)
{
    for (int i = 0; i <= n; i++)
    {
        graph[i].clear();
        disc[i] = 0;
        low[i] = INF;
        ap[i] = false;
    }
}

void AP(int n)
{
    Time = 0;
    for (int i = 1; i <= n; i++)
        if (!disc[i])
            ap[i] = (dfsAP(i, i) > 1);
}

int main()
{
    while (1)
    {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;

        reset(n);

        while (m--)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        AP(n);
        cout << count(ap.begin(), ap.begin() + n + 1, true) << endl;
    }
}