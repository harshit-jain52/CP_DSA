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
	ll n;
	cin >> n;
	ll a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	ll lim = 2 * n;
	vector<ll> mp(lim, 0);
	mp[0] = 1;

	ll xo = 0;
	ll ct = 0;
	for (int i = 0; i < n; i++)
	{
		xo ^= a[i];
		for (ll num = 0; num * num <= lim; num++)
		{
			if (((num * num) ^ xo) < lim)
				ct += mp[(num * num) ^ xo];
		}
		mp[xo]++;
	}

	cout << n * (n + 1) / 2 - ct << endl;
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