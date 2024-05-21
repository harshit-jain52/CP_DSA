#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int LOG = 20;

// Query: Find GCD of all values (on nodes) in path between two given nodes

vector<int> tree[N];
int val[N], depth[N];
int up[N][LOG], dp[N][LOG];

void dfs(int v, int pp, int dep)
{
	up[v][0] = pp;
	dp[v][0] = val[v];
	depth[v] = dep;

	for (int i = 1; i < LOG; i++)
	{
		up[v][i] = up[up[v][i - 1]][i - 1];
		dp[v][i] = __gcd(dp[v][i - 1], dp[up[v][i - 1]][i - 1]);
	}

	for (int ch : tree[v])
	{
		if (ch == pp)
			continue;
		dfs(ch, v, dep + 1);
	}
}

int pathVal(int u, int v)
{
	if (depth[u] < depth[v])
		swap(u, v);

	int ans = 0;

	// Lift to same level
	for (int i = LOG - 1; i >= 0; i--)
	{
		if ((depth[u] - depth[v]) & (1 << i))
		{
			ans = __gcd(ans, dp[u][i]);
			u = up[u][i];
		}
	}

	if (u == v)
		return __gcd(ans, val[u]);

	// Lift and evaluate till LCA
	for (int i = LOG - 1; i >= 0; i--)
	{
		if (up[u][i] != up[v][i])
		{
			ans = __gcd(ans, dp[u][i]);
			u = up[u][i];
			ans = __gcd(ans, dp[v][i]);
			v = up[v][i];
		}
	}

	ans = __gcd(ans, val[u]);
	ans = __gcd(ans, val[v]);
	return __gcd(ans, val[up[u][0]]);
}