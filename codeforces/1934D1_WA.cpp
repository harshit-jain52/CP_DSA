#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef unsigned long long ll;
const int M = 1e9 + 7;

void solve()
{
	ll m, n;
	cin >> n >> m;
	ll x = m ^ n;

	if (x < n)
	{
		cout << 1 << endl;
		cout << n << " " << m << endl;
		return;
	}

	vector<ll> v;
	v.push_back(n);

	for (int i = 62; i >= 0; i--)
	{
		x = (1LL << i);
		if ((bool)(x & m) == (bool)(x & n))
			continue;

		if ((bool)(x & n))
		{
			n = n ^ x;
			if (n == m)
				break;

			v.push_back(n);

			if (n < m)
			{
				cout << -1 << endl;
				return;
			}
		}
	}

	cout << v.size() << endl;
	for (auto it : v)
		cout << it << " ";
	cout << m << endl;
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