#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
int n, i, j, x, y;
int dp[101][101];

int func(int num, int l)
{
	int r = n - (num - l);
	if (num > n)
		return 1;
	if (dp[num][l] != -1)
		return dp[num][l];

	int ways = 0;
	if (num == x)
	{
		if (l == i)
			ways = func(num + 1, l + 1);
		else if (r == i)
			ways = func(num + 1, l);
		else
			ways = 0;
	}
	else if (num == y)
	{
		if (l == j)
			ways = func(num + 1, l + 1);
		else if (r == j)
			ways = func(num + 1, l);
		else
			ways = 0;
	}
	else
	{
		ways = (num != n) ? (func(num + 1, l + 1) + func(num + 1, l)) % M : 1;
	}

	return dp[num][l] = ways;
}

void solve()
{
	cin >> n >> i >> j >> x >> y;
	for (int i_ = 0; i_ <= n; i_++)
	{
		for (int j_ = 0; j_ <= n; j_++)
		{
			dp[i_][j_] = -1;
		}
	}

	bool inc = (i == x && j == y);
	bool dec = (i == (n - x + 1) && j == (n - y + 1));
	cout << func(1, 1) - inc - dec << endl;
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