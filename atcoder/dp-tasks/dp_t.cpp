#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
	FASTIO
	int n;
	cin >> n;
	string s;
	cin >> s;

	int dp[n + 1][n + 1];
	int pref[n + 1];
	dp[1][1] = 1;
	pref[0] = 0, pref[1] = 1;
	for (int i = 2; i <= n; i++)
		dp[1][i] = 0;

	for (int i = 2; i <= n; i++)
	{
		if (s[i - 2] == '<')
		{
			for (int j = 1; j <= i; j++)
				dp[i][j] = pref[j - 1];
		}
		else
		{
			for (int j = 1; j < i; j++)
				dp[i][j] = (pref[i - 1] + M - pref[j - 1]) % M;

			dp[i][i] = 0;
		}

		for (int j = 1; j <= i; j++)
			pref[j] = (pref[j - 1] + dp[i][j]) % M;
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = (ans + dp[n][i]) % M;

	cout << ans;
}