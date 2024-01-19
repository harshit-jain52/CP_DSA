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
	int n;
	cin >> n;
	ll a[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	vector<ll> oddpositives(n + 1, 0), evenpositives(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		evenpositives[i] += evenpositives[i - 1];
		oddpositives[i] += oddpositives[i - 1];

		if (a[i] > 0)
		{
			if (i % 2 == 0)
				evenpositives[i] += a[i];
			else
				oddpositives[i] += a[i];
		}
	}

	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ll temp = oddpositives[i - 1] + (evenpositives[n] - evenpositives[i]) + (oddpositives[n] - oddpositives[i]);
		if (i % 2 == 1)
			ans = max(ans, temp + a[i]);
		else
			ans = max(ans, temp);
	}

	cout << ans << endl;
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