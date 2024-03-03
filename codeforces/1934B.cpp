#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

int dp[32];
int func(int n)
{
	if (n == 0)
		return 0;
	if (dp[n] != -1)
		return dp[n];

	int ct = 1000;
	for (int i = 1; i <= 5; i++)
	{
		if (i * (i + 1) / 2 > n)
			break;
		ct = min(ct, 1 + func(n - i * (i + 1) / 2));
	}

	return dp[n] = ct;
}

void solve()
{
	int n;
	cin >> n;

	if (n <= 30)
	{
		cout << dp[n] << endl;
		return;
	}
	int ct = n / 15 - 1;
	n -= ct * 15;
	cout << ct + dp[n] << endl;
}

int main()
{
	FASTIO
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= 30; i++)
		func(i);

	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}