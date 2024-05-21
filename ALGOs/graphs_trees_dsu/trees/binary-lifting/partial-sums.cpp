#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int LOG = 20;

// Query: + u v x -> Add x to all nodes in path from u to v
// After all queries, print final value of each node

vector<int> tree[N];
int partial[N], depth[N];
int up[N][LOG];

void dfs(int v, int pp, int dep)
{
	up[v][0] = pp;
	depth[v] = dep;

	for (int i = 1; i < LOG; i++)
	{
		up[v][i] = up[up[v][i - 1]][i - 1];
	}

	for (int ch : tree[v])
	{
		if (ch == pp)
			continue;
		dfs(ch, v, dep + 1);
	}
}

int lca(int u, int v)
{
	if (depth[u] < depth[v])
		swap(u, v);

	for (int i = LOG - 1; i >= 0; i--)
	{
		if ((depth[u] - depth[v]) & (1 << i))
		{
			u = up[u][i];
		}
	}

	if (u == v)
		return u;

	for (int i = LOG - 1; i >= 0; i--)
	{
		if (up[u][i] != up[v][i])
		{
			u = up[u][i];
			v = up[v][i];
		}
	}

	return up[u][0];
}

void addX(int u, int v, int x)
{
	int lc = lca(u, v);

	// [u-lc) + [v-lc]
	partial[u] += x;
	partial[v] += x;
	partial[lc] -= x;
	partial[up[lc][0]] -= x;
}

void pushAll(int v, int pp)
{
	for (int ch : tree[v])
	{
		if (ch == pp)
			continue;
		pushAll(ch, v);
	}
	partial[up[v][0]] += partial[v];
}