#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, q;
	cin >> n >> q;
	ll a[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	while (q--)
	{
		ll k;
		cin >> k;
		vector<ll> arr(n);
		for (int i = 0; i < n; i++)
			arr[i] = a[i];

		ll op = k;
		ll ans = 0;
		for (int j = 60; j >= 0; j--)
		{
			ll ct = 0;
			ll num = (1LL << j);

			for (int i = 0; i < n; i++)
			{
				if ((num & arr[i]) == 0)
				{
					ll tmp = ((num - 1) & arr[i]);
					ct += (num - tmp);
					if (ct > op)
						break;
				}
			}

			if (op >= ct)
			{
				ans += num;
				for (int i = 0; i < n; i++)
				{
					if ((num & arr[i]) == 0)
					{
						ll tmp = ((num - 1) & arr[i]);
						arr[i] += (num - tmp);
					}
				}
				op -= ct;
			}
		}

		cout << ans << endl;
	}
}