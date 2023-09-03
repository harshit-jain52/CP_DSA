#include <bits/stdc++.h>
using namespace std;

// Detect Cycle in Directed Graph

const int N = 1e5 + 10;
vector<int> g[N];
vector<bool> visited;
vector<bool> recur_stack;

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