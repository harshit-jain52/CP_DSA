#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 998244353;
const int N = 1e3 + 5;

char grid[N][N];
int id[N][N];

int binExp(int a, int b)
{
	int ans = 1;
	while (b)
	{
		if (b & 1)
		{
			ans = (ans * 1LL * a) % M;
		}
		a = (a * 1LL * a) % M;
		b = b >> 1;
	}
	return ans;
}

void dfs(int x, int y, int h, int w, int c)
{
	if (x < 0 || x >= h || y < 0 || y >= w)
		return;
	if (grid[x][y] == '.' || id[x][y] != -1)
		return;

	id[x][y] = c;
	dfs(x - 1, y, h, w, c);
	dfs(x + 1, y, h, w, c);
	dfs(x, y - 1, h, w, c);
	dfs(x, y + 1, h, w, c);
}

int main()
{
	FASTIO
	int h, w;
	cin >> h >> w;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> grid[i][j];
			id[i][j] = -1;
		}
	}

	int comp = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (grid[i][j] == '.' || id[i][j] != -1)
				continue;
			dfs(i, j, h, w, comp++);
		}
	}

	int e = 0;
	int ct = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (grid[i][j] == '#')
				continue;
			ct++;
			set<int> st;
			if (i > 0 && grid[i - 1][j] == '#')
				st.insert(id[i - 1][j]);
			if (j > 0 && grid[i][j - 1] == '#')
				st.insert(id[i][j - 1]);
			if (i < h - 1 && grid[i + 1][j] == '#')
				st.insert(id[i + 1][j]);
			if (j < w - 1 && grid[i][j + 1] == '#')
				st.insert(id[i][j + 1]);

			e = (e + (comp - st.size() + 1)) % M;
		}
	}

	cout << (e * 1LL * binExp(ct, M - 2)) % M;
}