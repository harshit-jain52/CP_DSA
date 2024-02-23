#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

void solve()
{
	int n, q;
	cin >> n >> q;
	ll c[n];
	for (int i = 0; i < n; i++)
		cin >> c[i];

	ll totsum[n + 1];
	int onesum[n + 1];

	totsum[0] = onesum[0] = 0;
	for (int i = 0; i < n; i++)
	{
		onesum[i + 1] = (c[i] == 1) + onesum[i];
		totsum[i + 1] = c[i] + totsum[i];
	}

	while (q--)
	{
		int l, r;
		cin >> l >> r;

		if (r == l)
		{
			cout << "NO" << endl;
			continue;
		}

		int len = r - l + 1;
		int ones = onesum[r] - onesum[l - 1];
		ll rem = totsum[r] - totsum[l - 1] - ones;
		ll carry = rem - (len - ones);
		if (ones <= carry)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
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