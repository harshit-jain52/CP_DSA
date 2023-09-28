#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;
const int N = 2e5 + 2;
const int LOG = 20;

vector<int> tree[N];
int up[N][LOG];
int depth[N];

void dfs(int a, int par)
{
    for (int b : tree[a])
    {
        if (b == par)
            continue;
        depth[b] = 1 + depth[a];
        up[b][0] = a;

        for (int j = 1; j < LOG; j++)
        {
            up[b][j] = up[up[b][j - 1]][j - 1];
        }

        dfs(b, a);
    }
}

int getLCA(int a, int b)
{
    if (depth[a] < depth[b])
        return getLCA(b, a);

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

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    int root = 1;
    depth[root] = 0;
    dfs(1, 0);

    while (q--)
    {
        int a, b;
        cin >> a >> b;

        cout << depth[a] + depth[b] - 2 * depth[getLCA(a, b)] << endl;
    }
}