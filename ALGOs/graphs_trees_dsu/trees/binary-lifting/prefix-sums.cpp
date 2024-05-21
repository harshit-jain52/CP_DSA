#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int LOG = 20;

// Query: Find XOR of all values (on edges) in path between two given nodes

vector<pair<int, int>> tree[N];
int prefix[N], depth[N];
int up[N][LOG];

void dfs(int v, int pp, int dep, int val)
{
	up[v][0] = pp;
	depth[v] = dep;
	// Push weight of edge down onto node; prefix[] stores evaluation from root to node
	prefix[v] = prefix[pp] ^ val; // if sum, prefix[v]=prefix[pp]+val

	for (int i = 1; i < LOG; i++)
	{
		up[v][i] = up[up[v][i - 1]][i - 1];
	}

	for (auto ch : tree[v])
	{
		if (ch.first == pp)
			continue;
		dfs(ch.first, v, dep + 1, ch.second);
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

int pathVal(int u, int v)
{
	return prefix[u] ^ prefix[v];
	// if sum, prefix[u] + prefix[v] - 2*prefix[lca(u,v)]
}