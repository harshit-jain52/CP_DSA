#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;

int M;
const int N = 1e5 + 10;
vector<int> tree[N], leftprod[N], rightprod[N];
int down[N], ans[N], up[N];

int dfs1(int v, int par)
{
	int sz = tree[v].size();
	int arr[sz];

	for (int i = 0; i < sz; i++)
	{
		if (tree[v][i] == par)
		{
			arr[i] = 1;
			continue;
		}

		arr[i] = (dfs1(tree[v][i], v) + 1) % M;
	}

	leftprod[v].resize(sz);
	rightprod[v].resize(sz);
	leftprod[v][0] = arr[0];
	rightprod[v][sz - 1] = arr[sz - 1];

	for (int i = 1; i < sz; i++)
	{
		leftprod[v][i] = (leftprod[v][i - 1] * 1LL * arr[i]) % M;
		rightprod[v][sz - i - 1] = (rightprod[v][sz - i] * 1LL * arr[sz - i - 1]) % M;
	}

	return down[v] = rightprod[v][0];
}

void dfs2(int v, int par)
{
	int sz = tree[v].size();

	for (int i = 0; i < sz; i++)
	{
		if (tree[v][i] == par)
			continue;

		int left = (i != 0) ? leftprod[v][i - 1] : 1;
		int right = (i != sz - 1) ? rightprod[v][i + 1] : 1;
		up[v] = ((((left * 1LL * right) % M) * 1LL * up[par]) % M + 1) % M;
		ans[tree[v][i]] = (down[tree[v][i]] * 1LL * up[v]) % M;
		dfs2(tree[v][i], v);
	}
}

int main()
{
	FASTIO
	int n;
	cin >> n >> M;
	if (n == 1)
	{
		cout << 1;
		return 0;
	}

	for (int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}

	ans[1] = dfs1(1, 0);
	up[0] = 1;
	dfs2(1, 0);
	for (int i = 1; i <= n; i++)
		cout << ans[i] << endl;
}