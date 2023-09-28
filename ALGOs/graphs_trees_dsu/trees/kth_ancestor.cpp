#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int LOG = 20;

vector<int> tree[N];
int par[N];
int up[N][LOG]; // up[v][j] is (2^j)th ancestor of v
int depth[N];

void dfs(int v, int p) // setting up parents and depth
{
    par[v] = p;
    depth[v] = depth[p] + 1;

    for (int child : tree[v])
        dfs(child, v);
}

int ancestorBruteForce(int v, int k) // O(k)
{
    if (depth[v] < k)
        return -1;

    int ans = v;
    for (int i = 0; i < k; i++)
    {
        ans = par[v];
    }
    return ans;
}

int ancestorBinaryLifting(int v, int k) // O(logk)
{
    if (depth[v] < k)
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
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
    }

    int root = 1;
    depth[0] = -1;
    dfs(root, 0);

    for (int i = 1; i <= n; i++)
        up[i][0] = par[i];

    for (int i = 1; i <= n; i++) // O(NlogN)
    {
        int pow = 1;
        while ((1 << pow) <= n)
        {
            up[i][pow] = up[up[i][pow - 1]][pow - 1];
            pow++;
        }
    }
}