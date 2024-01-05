#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
typedef long double ld;
const int M = 1e9 + 7;

int main()
{
	FASTIO
	int n;
	cin >> n;
	int p[n + 1];
	ld sum_pow_09[n + 1];
	sum_pow_09[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
		sum_pow_09[i] = 1 + 0.9 * sum_pow_09[i - 1];
	}

	ld dp[n + 1][n + 1];
	for (int i = 0; i <= n; i++)
		dp[i][0] = 0;
	dp[1][1] = p[1];

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i][j] = p[i] + 0.9 * dp[i - 1][j - 1];
			if (i != j)
				dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}

	ld ans = INT_MIN;
	for (int k = 1; k <= n; k++)
	{
		ld factor = (ld)(1200) / sqrtl(k);
		for (int i = 1; i <= n; i++)
		{
			ans = max(ans, dp[i][k] / sum_pow_09[k] - factor);
		}
	}

	cout << setprecision(20) << ans;
}