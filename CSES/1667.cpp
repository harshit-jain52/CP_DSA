#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];

bool visited[N];
int level[N];
int parent[N];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty())
    {
        int cur_v = q.front();
        q.pop();
        for (int child : g[cur_v])
        {
            if (!visited[child])
            {
                q.push(child);
                visited[child] = 1;
                parent[child] = cur_v;
                level[child] = level[cur_v] + 1;
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    level[n] = -1;

    for (int i = 0; i < m; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        g[n1].push_back(n2);
        g[n2].push_back(n1);
    }

    parent[1] = 0;
    bfs(1);

    if (level[n] == -1)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        vector<int> path;
        int vertex = n;
        while (vertex != 0)
        {
            path.push_back(vertex);
            vertex = parent[vertex];
        }

        cout << path.size() << endl;
        for (int i = path.size() - 1; i >= 0; i--)
        {
            cout << path[i] << " ";
        }
    }
}