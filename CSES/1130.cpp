#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;
const int N = 2e5 + 5;

vector<int> t[N];
int dp[N][2];

void dfs(int v, int par)
{
    for (int child : t[v])
    {
        if (child == par)
            continue;
        dfs(child, v);

        dp[v][0] += max(dp[child][0], dp[child][1]);
        // vertex not taken; every child taken or not taken
    }

    for (int child : t[v])
    {
        if (child == par)
            continue;

        dp[v][1] = max(dp[v][1], 1 + dp[child][0] + (dp[v][0] - max(dp[child][0], dp[child][1])));
        // this vertex is taken, now if one child is taken no other children should be taken
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        t[a].push_back(b);
        t[b].push_back(a);
    }

    dfs(1, -1);

    cout << max(dp[1][0], dp[1][1]);
}