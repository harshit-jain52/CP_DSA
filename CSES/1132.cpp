#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;
const int N = 2e5 + 2;

vector<int> tree[N];
int dp1[N], dp2[N], ans[N];

void dfs1(int v, int par)
{
    dp1[v] = 0;
    dp2[v] = 0;

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

void dfs2(int v, int par, int to_p)
{
    ans[v] = max(to_p, dp1[v]);

    for (int child : tree[v])
    {
        if (child == par)
            continue;

        if (dp1[v] == dp1[child] + 1)
            dfs2(child, v, max(to_p, dp2[v]) + 1);
        else
            dfs2(child, v, ans[v] + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs1(1, -1);
    dfs2(1, -1, 0);

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
}