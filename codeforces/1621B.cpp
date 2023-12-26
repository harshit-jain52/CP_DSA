#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const ll INF = 1e15;

void solve()
{
	int n;
	cin >> n;

	int l_min = 1e9 + 1, r_max = -1;
	ll lcost = INF, rcost = INF, lrcost = INF;

	while (n--)
	{
		int l, r;
		ll c;
		cin >> l >> r >> c;
		if (l < l_min)
		{
			l_min = l;
			lcost = c;
			lrcost = INF;
		}
		if (r > r_max)
		{
			r_max = r;
			rcost = c;
			lrcost = INF;
		}

		if (l == l_min)
			lcost = min(lcost, c);
		if (r == r_max)
			rcost = min(rcost, c);
		if (l == l_min && r == r_max)
			lrcost = min(lrcost, c);

		cout << min(lcost + rcost, lrcost) << endl;
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