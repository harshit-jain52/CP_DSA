#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;
const int N = 2e5 + 1;
int dp[N][10];

int func(int dig, int op)
{
	if (op == 0)
		return 1;
	if (dp[op][dig] != -1)
		return dp[op][dig];

	int ct = 0;
	int num = dig + 1;
	ct = (ct + func(num % 10, op - 1)) % M;
	if (num == 10)
	{
		ct = (ct + func(1, op - 1)) % M;
	}

	return dp[op][dig] = ct;
}

void solve()
{
	int n, m;
	cin >> n >> m;

	int ans = 0;
	string str = to_string(n);
	for (int i = 0; i < str.size(); i++)
	{
		ans = (ans + dp[m][str[i] - '0']) % M;
	}

	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(dp, -1, sizeof(dp));
	for (int num = 1; num < N; num++)
		for (int i = 0; i <= 9; i++)
			func(i, num);

	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}