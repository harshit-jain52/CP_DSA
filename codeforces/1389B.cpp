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
	int n, k, z;
	cin >> n >> k >> z;

	ll a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	ll maxpair[n], pref[n];
	pref[0] = a[0];
	maxpair[0] = 0;
	for (int i = 1; i < n; i++)
	{
		maxpair[i] = max(maxpair[i - 1], a[i] + a[i - 1]);
		pref[i] = pref[i - 1] + a[i];
	}

	ll ans = 0;
	for (int i = 0; i <= z; i++)
	{
		if (k > 2 * i)
			ans = max(ans, pref[k - 2 * i] + i * maxpair[k - 2 * i]);
		if (i > 0 && k > 2 * i - 1)
			ans = max(ans, pref[k - 2 * i + 1] + (i - 1) * maxpair[k - 2 * i + 1] + a[k - 2 * i]);
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