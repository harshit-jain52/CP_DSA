#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];
vector<bool> visited;
vector<bool> recur_stack;
vector<int> order;

void dfs(int vertex)
{
    visited[vertex] = true;
    for (int child : g[vertex])
    {
        if (!visited[child])
            dfs(child);
    }
    order.push_back(vertex);
}

bool detectCycle(int vertex)
{
    recur_stack[vertex] = 1;
    visited[vertex] = true;
    bool ans = false;

    for (auto child : g[vertex])
    {
        if (recur_stack[child])
        {
            ans = true;
            break;
        }
        if (visited[child])
            continue;

        ans |= detectCycle(child);
    }

    recur_stack[vertex] = 0;

    return ans;
}

void topological_sort(int n)
{
    visited.assign(n + 1, false);
    order.clear();

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            dfs(i);
    }
    reverse(order.begin(), order.end());
}

bool isCycle(int n)
{
    visited.assign(n + 1, false);
    recur_stack.assign(n + 1, false);

    bool final = false;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            final |= detectCycle(i);
    }

    return final;
}

int main()
{
    int n, m;
    cin >> n >> m;

    while (m--)
    {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
    }

    visited.assign(n + 1, false);

    if (isCycle(n))
        cout << "IMPOSSIBLE";
    else
    {
        topological_sort(n);

        for (auto it : order)
        {
            cout << it << " ";
        }
    }
}
