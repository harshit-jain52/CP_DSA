#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int LOG = 20;

vector<int> tree[N];
int par[N];
int up[N][LOG];
int depth[N];

void dfs(int v, int p)
{
    par[v] = p;
    depth[v] = depth[p] + 1;

    for (int child : tree[v])
    {
        if (child == p)
            continue;
        dfs(child, v);
    }
}

int ancestorBinaryLifting(int v, int k)
{
    if (k > depth[v])
        return -1;

    int ans = v;
    for (int pow = 0; pow < LOG; pow++)
    {
        if (k & (1 << pow))
            ans = up[ans][pow];
    }

    return ans;
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
    depth[0] = -1;
    dfs(root, 0);

    for (int i = 1; i <= n; i++)
        up[i][0] = par[i];

    for (int i = 1; i <= n; i++)
    {
        int pow = 1;
        while ((1 << pow) <= n)
        {
            up[i][pow] = up[up[i][pow - 1]][pow - 1];
            pow++;
        }
    }

    while (q--)
    {
        int x, k;
        cin >> x >> k;
        cout << ancestorBinaryLifting(x, k) << endl;
    }
}