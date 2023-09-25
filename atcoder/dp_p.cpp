#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;
const int N = 1e5 + 5;

vector<int> tree[N];
int dp[N][2];

int dfs(int v, bool prev_color, int par) // white=0,black=1
{
    if (dp[v][prev_color] != -1)
        return dp[v][prev_color];

    int ans;

    if (prev_color)
    {
        int ct = 1;
        for (int child : tree[v])
        {
            if (child == par)
                continue;
            ct = (ct * 1LL * dfs(child, 0, v)) % M;
        }

        ans = ct;
    }
    else
    {
        int ct0 = 1, ct1 = 1;

        for (int child : tree[v])
        {
            if (child == par)
                continue;
            ct0 = (ct0 * 1LL * dfs(child, 0, v)) % M;
            ct1 = (ct1 * 1LL * dfs(child, 1, v)) % M;
        }
        ans = (ct0 + ct1) % M;
    }

    return dp[v][prev_color] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, -1, sizeof(dp));

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    cout << dfs(1, 0, -1) << endl;
}