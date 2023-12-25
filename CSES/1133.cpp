#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;

const int M = 1e9 + 7;
const int N = 2e5 + 5;
vector<int> tree[N];
ll subtreeSize[N];
ll ans[N];

void dfs1(int v, int par, ll depth)
{
    ans[1] += depth;
    subtreeSize[v] = 1;

    for (int child : tree[v])
    {
        if (child == par)
            continue;

        dfs1(child, v, depth + 1);
        subtreeSize[v] += subtreeSize[child];
    }
}

void dfs2(int v, int par, int n)
{
    for (int child : tree[v])
    {
        if (child == par)
            continue;
        ans[child] = ans[v] + (n - subtreeSize[child]) - subtreeSize[child];
        // depth of all nodes outside of child's subtree increases by 1
        // depth of all nodes in child's subtree decreases by 1
        dfs2(child, v, n);
    }
}

int main()
{
    FASTIO

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs1(1, 0, 0);
    dfs2(1, 0, n);

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
}