#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;
const int N = 2e5 + 5;

int dp[N];

int func(int idx, int a[], int n)
{
	if (idx >= n)
		return 0;

	if (dp[idx] != -1)
		return dp[idx];

	int ans = INT_MAX;
	if (idx + a[idx] < n)
	{
		ans = min(ans, func(idx + a[idx] + 1, a, n));
	}

	ans = min(ans, 1 + func(idx + 1, a, n));

	return dp[idx] = ans;
}

void reset(int n)
{
	for (int i = 0; i <= n; i++)
	{
		dp[i] = -1;
	}
}

void solve()
{
	int n;
	cin >> n;
	reset(n);

	int a[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	cout << func(0, a, n) << endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}