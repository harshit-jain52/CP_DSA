// Lowest Common Ancestor

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int LOG = 20;

vector<int> tree[N];
int up[N][LOG]; // up[v][j] is (2^j)th ancestor of v
int depth[N];

void dfs(int a)
{
    for (int b : tree[a])
    {
        depth[b] = depth[a] + 1;
        up[b][0] = a;
        for (int j = 1; j < LOG; j++)
            up[b][j] = up[up[b][j - 1]][j - 1];

        dfs(b);
    }
}

int lcaBruteForce(int a, int b) // O(N)
{
    if (depth[a] < depth[b])
        swap(a, b);

    while (depth[a] > depth[b])
        a = up[a][0];

    while (a != b)
    {
        a = up[a][0];
        b = up[b][0];
    }

    return a;
}

int lcaBinaryLifting(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);

    int k = depth[a] - depth[b];

    for (int j = LOG - 1; j >= 0; j--)
    {
        if (k & (1 << j))
            a = up[a][j];
    }

    if (a == b)
        return a;

    for (int j = LOG - 1; j >= 0; j--)
    {
        if (up[a][j] != up[b][j])
        {
            a = up[a][j];
            b = up[b][j];
        }
    }
    // Now a and b are both immediate children of LCA

    return up[a][0];
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
    }

    int root = 1;
    depth[root] = 0;
    up[root][0] = 0;
    
    dfs(root);
}