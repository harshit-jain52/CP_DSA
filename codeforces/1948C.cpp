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
bool vis[2][N][2];
vector<pair<int, int>> movements = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool move(int x, int y, int type, int n, vector<string> &grid)
{
	if (x < 0 || y < 0 || x >= 2 || y >= n)
		return false;
	if (x == 1 && y == n - 1)
		return true;
	if (vis[x][y][type])
		return false;
	vis[x][y][type] = true;
	bool canReach = false;
	if (type == 0)
	{
		for (auto m : movements)
		{
			canReach |= move(x + m.first, y + m.second, 1, n, grid);
		}
	}
	else
	{
		if (grid[x][y] == '>')
			canReach |= move(x, y + 1, 0, n, grid);
		else
			canReach |= move(x, y - 1, 0, n, grid);
	}

	return canReach;
}

bool solve()
{
	int n;
	cin >> n;
	vector<string> grid(2);
	cin >> grid[0] >> grid[1];
	for (int i = 0; i < n; i++)
		vis[0][i][0] = vis[1][i][0] = vis[0][i][1] = vis[1][i][1] = false;

	return move(0, 0, 0, n, grid);
}

int main()
{
	FASTIO
	int t;
	cin >> t;
	while (t--)
	{
		if (solve())
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
	}
}