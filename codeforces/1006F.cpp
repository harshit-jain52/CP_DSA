#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
int n, m;
ll k;
ll grid[25][25];
map<ll, ll> ct1[25][25];
ll ans = 0;

void dfs1(int x, int y, ll XOR)
{
	if ((x + y) == (n + m - 2) / 2)
	{
		ct1[x][y][XOR ^ grid[x][y]]++;
		return;
	}
	if (x < n - 1)
		dfs1(x + 1, y, XOR ^ grid[x][y]);
	if (y < m - 1)
		dfs1(x, y + 1, XOR ^ grid[x][y]);
}

void dfs2(int x, int y, ll XOR)
{
	if ((x + y) == (n + m - 2) / 2)
	{
		ans += ct1[x][y][XOR ^ k];
		return;
	}
	if (x > 0)
		dfs2(x - 1, y, XOR ^ grid[x][y]);
	if (y > 0)
		dfs2(x, y - 1, XOR ^ grid[x][y]);
}

int main()
{
	FASTIO
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> grid[i][j];

	dfs1(0, 0, 0);
	dfs2(n - 1, m - 1, 0);
	cout << ans;
}