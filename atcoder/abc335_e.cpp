#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> ii;
const int M = 1e9 + 7;
const int N = 2e5 + 5;

vector<int> graph[N];
int A[N];
int dp[N];
vector<int> canReach(N, -1);

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

bool reachdfs(int v, int n)
{
	if (v == n)
		return true;
	if (canReach[v] != -1)
		return canReach[v];

	bool ans = false;
	for (int next : graph[v])
		ans |= reachdfs(next, n);

	return canReach[v] = ans;
}

int dfs(int v, int n)
{
	if (v == n)
		return 1;

	if (dp[v] != -1)
		return dp[v];

	int ans = 0;
	for (int next : graph[v])
	{
		if (reachdfs(next, n))
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

	vector<ii> edges;
	while (m--)
	{
		int u, v;
		cin >> u >> v;
		edges.push_back((ii){u, v});
		if (A[u] == A[v])
			unionBySize(u, v);
	}

	for (auto e : edges)
	{
		int u = find(e.first);
		int v = find(e.second);

		if (u == v)
			continue;

		if (A[u] < A[v])
			graph[u].push_back(v);
		else
			graph[v].push_back(u);
	}

	cout << dfs(find(1), find(n));
}