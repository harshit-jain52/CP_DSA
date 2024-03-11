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
	int n, m, k, d;
	cin >> n >> m >> k >> d;
	ll a[n][m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	ll bridges[n + 1];
	bridges[0] = 0;
	for (int i = 0; i < n; i++)
	{
		map<int, ll> mp;
		multiset<ll> ms;
		ms.insert(1);
		mp[0] = 1;

		for (int j = 1; j < m - 1; j++)
		{
			ll tmp = (*ms.begin()) + a[i][j] + 1;
			mp[j] = tmp;
			ms.insert(tmp);

			if (ms.size() == d + 2)
			{
				ms.erase(ms.find(mp[j - d - 1]));
			}
		}
		ll cost = 1 + (*ms.begin());
		bridges[i + 1] = cost;
	}

	ll total = 1e17;
	for (int i = 1; i <= n; i++)
		bridges[i] += bridges[i - 1];

	for (int i = k; i <= n; i++)
	{
		total = min(total, bridges[i] - bridges[i - k]);
	}
	cout << total << endl;
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