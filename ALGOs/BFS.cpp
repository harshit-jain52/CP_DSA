#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> t[N];

bool visited[N];
int level[N];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty())
    {
        int cur_v = q.front();
        q.pop();
        for (int child : t[cur_v])
        {
            if (!visited[child])
            {
                q.push(child);
                visited[child] = 1;
                level[child] = level[cur_v] + 1;
            }
        }
    }

    // Time Complexity: O(V + E);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        t[n1].push_back(n2);
        t[n2].push_back(n1);
    }
}