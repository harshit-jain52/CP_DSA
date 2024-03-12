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
	int n, m, k;
	cin >> n >> m >> k;
	ll a[n];
	ll max1 = 0, max2 = 0, maxi;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (i)
		{
			ll diff = a[i] - a[i - 1];
			if (diff > max1)
			{
				max2 = max1;
				max1 = diff;
				maxi = i;
			}
			else if (diff > max2)
			{
				max2 = diff;
			}
		}
	}

	ll d[m], f[k];
	ll ans = max1;

	for (int i = 0; i < m; i++)
		cin >> d[i];
	for (int j = 0; j < k; j++)
		cin >> f[j];

	sort(d, d + m);
	sort(f, f + k);

	int i = 0, j = k - 1;
	while (i < m && j >= 0)
	{
		ll sum = d[i] + f[j];
		auto it = upper_bound(a, a + n, sum);
		int idx = it - a;
		if (idx > maxi)
		{
			j--;
			continue;
		}
		if (idx < maxi)
		{
			i++;
			continue;
		}

		ll diff1 = sum - a[idx - 1], diff2 = a[idx] - sum;
		ans = min(ans, max({max2, diff1, diff2}));
		if (diff2 > diff1)
			i++;
		else
			j--;
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