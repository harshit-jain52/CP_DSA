#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
vector<int> tree[N];
ll l[N], r[N], dp[N][2];

void dfs(int v, int par)
{
	dp[v][0] = dp[v][1] = 0;

	for (int child : tree[v])
	{
		if (child == par)
			continue;
		dfs(child, v);

		dp[v][0] += max(dp[child][0] + abs(l[v] - l[child]), dp[child][1] + abs(l[v] - r[child]));
		dp[v][1] += max(dp[child][0] + abs(r[v] - l[child]), dp[child][1] + abs(r[v] - r[child]));
	}
}

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		tree[i].clear();
		cin >> l[i] >> r[i];
	}

	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	dfs(1, 0);
	cout << max(dp[1][0], dp[1][1]) << endl;
}

int main()
{
	FASTIO
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}