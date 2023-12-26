#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int N = 1e5 + 2;

ll dp[N][26];

ll func(int idx, char prev, int n, string &s)
{
	if (dp[idx][prev - 'a'] != -1)
		return 0;
	if (idx == n)
		return dp[idx][prev - 'a'] = 1;

	ll ct = 1;
	ct += func(idx + 1, s[idx], n, s);
	ct += func(idx + 1, prev, n, s);

	return dp[idx][prev - 'a'] = ct;
}

void reset(int n)
{
	for (int i = 0; i <= n; i++)
		for (int j = 0; j < 26; j++)
			dp[i][j] = -1;
}

void solve()
{
	int n;
	cin >> n;
	reset(n);
	string s;
	cin >> s;

	cout << func(1, s[0], n, s) << endl;
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