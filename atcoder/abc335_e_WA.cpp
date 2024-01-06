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

vector<int> graph[N];
int A[N];
int dp[N];
vector<bool> canReach(N, false);

int parent[N];
int set_size[N];
void make(int v)
{
	parent[v] = v;
	set_size[v] = 1;
}

int find(int v)
{
	if (v == parent[v])
		return v;
	return parent[v] = find(parent[v]);
}

void unionBySize(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a != b)
	{
		if (set_size[a] < set_size[b])
			swap(a, b);

		parent[b] = a;
		set_size[a] += set_size[b];
	}
}

void revdfs(int v)
{
	canReach[v] = true;
	for (int prev : graph[v])
	{
		if (canReach[prev])
			continue;
		if (A[prev] < A[v])
			revdfs(prev);
	}
}

int dfs(int v, int n)
{
	if (v == n)
		return 1;

	int ans = 0;
	if (dp[v] != -1)
		return dp[v];

	for (int next : graph[v])
	{
		if (A[next] < A[v])
			continue;
		if (canReach[next])
			ans = max(ans, 1 + dfs(next, n));
	}

	return dp[v] = ans;
}

int main()
{
	FASTIO
	memset(dp, -1, sizeof(dp));

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> A[i];
		make(i);
	}

	vector<pair<int, int>> edges;
	while (m--)
	{
		int u, v;
		cin >> u >> v;
		edges.push_back({u, v});
		if (A[u] == A[v])
			unionBySize(u, v);
	}

	for (auto e : edges)
	{
		int u = find(e.first);
		int v = find(e.second);

		if (u == v)
			continue;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	revdfs(n);
	
	cout << dfs(1, n);
}