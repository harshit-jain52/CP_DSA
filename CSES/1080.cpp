#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
int n;
string s;
int dp[501][501];
int fact[501], fact_inv[501];

int binExpIter(int a, int b)
{
	int ans = 1;
	while (b)
	{
		if (b & 1)
			ans = (ans * 1LL * a) % M;

		a = (a * 1LL * a) % M;
		b = b >> 1;
	}
	return ans;
}

int func(int l, int r)
{
	int len = r - l + 1;
	if (len & 1)
		return 0;
	if (len == 2)
		return s[l] == s[r];
	if (l == r)
		return 1;
	if (dp[l][r] != -1)
		return dp[l][r];

	int ways = 0;
	if (s[l + 1] == s[l])
		ways = (ways + ((len / 2) * 1LL * func(l + 2, r)) % M) % M;
	if (s[l] == s[r])
		ways = (ways + func(l + 1, r - 1)) % M;
	for (int i = l + 2; i < r; i++)
	{
		if (s[i] == s[l])
		{
			int len1 = i - 1 - (l + 1) + 1, len2 = r - (i + 1) + 1;
			int arrange = (fact[len1 / 2 + len2 / 2 + 1] * 1LL * ((fact_inv[len1 / 2 + 1] * 1LL * fact_inv[len2 / 2]) % M)) % M;
			ways = (ways + (((func(l + 1, i - 1) * 1LL * func(i + 1, r)) % M) * 1LL * arrange) % M) % M;
		}
	}
	return dp[l][r] = ways;
}

int main()
{
	FASTIO
	cin >> s;
	n = s.size();
	memset(dp, -1, sizeof(dp));
	fact[0] = 1, fact_inv[0] = 1;
	for (int i = 1; i <= 500; i++)
	{
		fact[i] = (fact[i - 1] * 1LL * i) % M;
		fact_inv[i] = binExpIter(fact[i], M - 2);
	};
	cout << func(0, n - 1);
}