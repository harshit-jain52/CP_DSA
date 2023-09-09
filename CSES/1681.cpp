#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N = 1e5 + 5;
const int M = 1e9 + 7;

vector<int> g[N];
int dp[N];
int n;

int dfs(int vertex)
{
    if (vertex == n)
        return 1;
    if (dp[vertex] != -1)
        return dp[vertex];

    int ct = 0;
    for (auto child : g[vertex])
    {
        ct = (ct + dfs(child)) % M;
    }

    return dp[vertex] = ct;
}

int main()
{
    memset(dp, -1, sizeof(dp));

    int m;
    cin >> n >> m;

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    cout << dfs(1);
}