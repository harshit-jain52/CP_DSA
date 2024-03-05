#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int N = 2001;

ll dp[N][N][2];
ll func(int idx, int num_left, vector<pair<ll, ll>> &ba, int ct)
{
	if (num_left == 0)
		return 0;
	if (idx < 0)
		return 1e15;

	if (num_left == ct && dp[idx][num_left][1] != -1)
		return dp[idx][num_left][1];
	if (num_left != ct && dp[idx][num_left][0] != -1)
		return dp[idx][num_left][0];

	ll add;
	if (num_left == 1)
		add = ba[idx].second - ba[idx].first;
	else if (num_left == ct)
		add = ba[idx].second + ba[idx].first;
	else
		add = ba[idx].second;

	return dp[idx][num_left][num_left == ct] = min(add + func(idx - 1, num_left - 1, ba, ct), func(idx - 1, num_left, ba, ct));
}

void solve()
{
	int n;
	ll l;
	cin >> n >> l;
	vector<pair<ll, ll>> ba(n);
	for (int i = 0; i < n; i++)
		cin >> ba[i].second >> ba[i].first;

	sort(ba.begin(), ba.end());
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			dp[i][j][0] = dp[i][j][1] = -1;
		}
	}

	for (int i = n; i >= 2; i--)
	{
		if (func(n - 1, i, ba, i) <= l)
		{
			cout << i << endl;
			return;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (ba[i].second <= l)
		{
			cout << 1 << endl;
			return;
		}
	}

	cout << 0 << endl;
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