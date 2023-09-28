#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int LOG = 20;

vector<int> tree[N];
int up[N][LOG];
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

int get_lca(int a, int b)
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

    return up[a][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    for (int i = 2; i <= n; i++)
    {
        int e;
        cin >> e;
        tree[e].push_back(i);
    }

    int root = 1;
    depth[root] = 0;
    up[root][0] = 0;

    dfs(root);

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << get_lca(a, b) << endl;
    }
}