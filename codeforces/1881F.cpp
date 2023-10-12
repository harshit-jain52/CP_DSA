#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;
const int N = 2e5 + 5;

vector<int> tree[N];
vector<bool> marked(N);
int dp1[N], dp2[N], ans[N];

void dfs1(int v, int par)
{
    dp1[v] = INT_MIN;
    dp2[v] = INT_MIN;

    if (marked[v])
    {
        dp1[v] = 0;
        dp2[v] = 0;
    }
    for (int child : tree[v])
    {
        if (child == par)
            continue;

        dfs1(child, v);

        if (1 + dp1[child] > dp1[v])
        {
            dp2[v] = dp1[v];
            dp1[v] = 1 + dp1[child];
        }
        else if (1 + dp1[child] > dp2[v])
        {
            dp2[v] = 1 + dp1[child];
        }
    }
}

void dfs2(int v, int par, int up)
{
    ans[v] = max(up, dp1[v]);

    for (int child : tree[v])
    {
        if (child == par)
            continue;

        if (dp1[v] == dp1[child] + 1 && dp1[v] >= 0)
            dfs2(child, v, max(up, dp2[v]) + 1);
        else
            dfs2(child, v, ans[v] + 1);
    }
}

void reset(int n)
{
    for (int i = 0; i <= n; i++)
    {
        tree[i].clear();
        marked[i] = false;
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;
    reset(n);

    while (k--)
    {
        int a;
        cin >> a;
        marked[a] = true;
    }

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs1(1, -1);
    dfs2(1, -1, INT_MIN);

    // for(int i=1;i<=n;i++){
    // 	cout << ans[i] << " ";
    // }

    int minans = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        minans = min(minans, ans[i]);
    }
    cout << minans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}