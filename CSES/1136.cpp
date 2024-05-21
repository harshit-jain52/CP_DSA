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
const int LOG = 20;

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

void addPath(int u, int v)
{
	int lc = lca(u, v);

	partial[u]++;
	partial[v]++;
	partial[lc]--;
	partial[up[lc][0]]--;
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

int main()
{
	FASTIO
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs(1, 0, 0);

	while (m--)
	{
		int a, b;
		cin >> a >> b;
		addPath(a, b);
	}

	pushAll(1, 0);
	for (int i = 1; i <= n; i++)
		cout << partial[i] << " ";
}