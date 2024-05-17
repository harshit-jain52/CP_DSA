#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> t[N];
int depth[N], height[N];

void dfs(int vertex, int parent = -1)
{
    // take action on vertex after entering the vertex
    for (int child : t[vertex])
    {
        // take action on child before entering the child node
        if (child == parent)
            continue;

        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);

        // take action on child after exiting child node
        height[vertex] = max(height[vertex], height[child] + 1);
    }

    // take action on vertex before exiting the vertex
}

// TC: O(N)