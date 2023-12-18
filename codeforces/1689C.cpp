#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;
const int N = 3e5 + 5;

vector<int> tree[N];
int startTime[N], endTime[N];
int subtreeSize[N];
int timer;

void reset(int n)
{
	for (int i = 0; i <= n; i++)
	{
		startTime[i] = 0;
		endTime[i] = 0;
		subtreeSize[i] = 0;
		tree[i].clear();
	}
	timer = 0;
}

void eulerTour(int v, int par)
{
	startTime[v] = timer++;
	for (int child : tree[v])
	{
		if (child == par)
			continue;
		eulerTour(child, v);
	}
	endTime[v] = timer;
	subtreeSize[v] = endTime[v] - startTime[v] - 1;
}

int dfs(int v, int par)
{
	int arr[2], idx = 0;
	for (int child : tree[v])
	{
		if (child == par)
			continue;
		arr[idx++] = child;
	}

	if (idx == 0)
		return 0;
	if (idx == 1)
		return subtreeSize[arr[0]];

	return max(subtreeSize[arr[0]] + dfs(arr[1], v), subtreeSize[arr[1]] + dfs(arr[0], v));
}

void solve()
{
	int n;
	cin >> n;
	reset(n);

	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	eulerTour(1, -1);
	cout << dfs(1, -1) << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}