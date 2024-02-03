#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
#define pii pair<int, int>
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
	FASTIO
	int n;
	cin >> n;
	vector<string> grid(n);
	for (int i = 0; i < n; i++)
		cin >> grid[i];

	int i1, j1, i2, j2;
	bool found = false;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (grid[i][j] == 'P')
			{
				if (!found)
				{
					i1 = i;
					j1 = j;
					found = true;
				}
				else
				{
					i2 = i;
					j2 = j;
				}
			}
		}
	}

	vector<pii> steps = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

	int dist[n][n][n][n];
	memset(dist, -1, sizeof(dist));
	queue<pair<pii, pii>> q;
	q.push({{i1, j1}, {i2, j2}});
	dist[i1][j1][i2][j2] = 0;

	int ans = -1;
	while (!q.empty())
	{
		auto curr = q.front();
		q.pop();
		i1 = curr.first.first;
		j1 = curr.first.second;
		i2 = curr.second.first;
		j2 = curr.second.second;
		if (i1 == i2 && j1 == j2)
		{
			ans = dist[i1][j1][i2][j2];
			break;
		}

		for (auto step : steps)
		{
			int di = step.first, dj = step.second;

			int i1_new = i1 + di, j1_new = j1 + dj;
			if (!(i1_new >= 0 && i1_new < n && j1_new >= 0 && j1_new < n && grid[i1_new][j1_new] != '#'))
			{
				i1_new = i1;
				j1_new = j1;
			}

			int i2_new = i2 + di, j2_new = j2 + dj;
			if (!(i2_new >= 0 && i2_new < n && j2_new >= 0 && j2_new < n && grid[i2_new][j2_new] != '#'))
			{
				i2_new = i2;
				j2_new = j2;
			}
			if (dist[i1_new][j1_new][i2_new][j2_new] == -1)
			{
				dist[i1_new][j1_new][i2_new][j2_new] = 1 + dist[i1][j1][i2][j2];
				q.push({{i1_new, j1_new}, {i2_new, j2_new}});
			}
		}
	}

	cout << ans;
}