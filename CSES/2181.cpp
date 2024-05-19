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
int dp[11][1001][1024];
int all1;

int tile(int i, int j, int mask)
{
	if (j == m)
		return (mask == all1);
	if (i == n)
		return tile(0, j + 1, mask);
	if (dp[i][j][mask] != -1)
		return dp[i][j][mask];

	int ct = 0;
	bool upbit = mask & (1 << (n - 1));
	if (!upbit)
	{
		ct = tile(i + 1, j, ((mask << 1) | 1) & all1);
	}
	else
	{
		if (i > 0)
		{
			bool leftbit = mask & 1;
			if (!leftbit)
				ct = tile(i + 1, j, ((mask << 1) | 3) & all1);
		}
		ct = (ct + tile(i + 1, j, (mask << 1) & all1)) % M;
	}

	return dp[i][j][mask] = ct;
}

int main()
{
	FASTIO
	cin >> n >> m;
	all1 = (1 << n) - 1;
	memset(dp, -1, sizeof(dp));
	cout << tile(0, 0, all1);
}