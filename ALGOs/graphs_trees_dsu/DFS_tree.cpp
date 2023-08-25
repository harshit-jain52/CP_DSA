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

    // Time Complexity O(V+E)
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

    // find diameter
    int root = 1, maxdepth = -1, max_d_node;
    dfs(root);

    for (int i = 1; i <= n; i++)
    {
        if (depth[i] > maxdepth)
        {
            maxdepth = depth[i];
            max_d_node = i;
        }
        depth[i] = 0; // reset
    }

    dfs(max_d_node);

    int diameter = *max_element(depth + 1, depth + n + 1);
    cout << diameter << endl;
}