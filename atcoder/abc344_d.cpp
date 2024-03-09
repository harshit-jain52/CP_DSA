#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

int dp[101][101];
vector<string> a[101];
string T;
int n;

bool isPrefix(string &s, int l)
{
	int i;
	for (i = 0; i < s.size(); i++)
	{
		if (i + l >= T.size())
			return false;
		if (s[i] != T[i + l])
			return false;
	}
	return true;
}

int func(int l, int idx)
{
	if (l == T.size())
		return 0;
	if (idx == n)
		return 1e4;

	if (dp[l][idx] != -1)
		return dp[l][idx];

	int ans = 1e4;
	for (string s : a[idx])
	{
		if (isPrefix(s, l))
			ans = min(ans, 1 + func(l + s.size(), idx + 1));
		ans = min(ans, func(l, idx + 1));
	}

	return dp[l][idx] = ans;
}

int main()
{
	FASTIO
	memset(dp, -1, sizeof(dp));
	cin >> T;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int sz;
		cin >> sz;
		for (int j = 0; j < sz; j++)
		{
			string s;
			cin >> s;
			a[i].push_back(s);
		}
	}
	int ans = func(0, 0);
	if (ans > 100)
		cout << -1;
	else
		cout << ans;
}