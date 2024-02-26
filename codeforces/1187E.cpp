#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int N = 2e5 + 10;
vector<int> tree[N];
int subtreeSize[N];
ll ans[N];

ll dfs1(int v, int par)
{
	subtreeSize[v] = 1;
	ll points = 0;

	for (int child : tree[v])
	{
		if (child == par)
			continue;

		points += dfs1(child, v);
		subtreeSize[v] += subtreeSize[child];
	}

	return (points + subtreeSize[v]);
}

void dfs2(int v, int par, int n)
{
	for (int child : tree[v])
	{
		if (child == par)
			continue;

		ans[child] = ans[v] + (n - subtreeSize[child]) - subtreeSize[child];
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
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	ans[1] = dfs1(1, 0);
	dfs2(1, 0, n);

	ll final = 0;
	for (int i = 1; i <= n; i++)
		final = max(final, ans[i]);

	cout << final;
}