#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
	FASTIO
	ll n;
	int k;
	cin >> n >> k;
	ll a[k];
	for (int i = 0; i < k; i++)
		cin >> a[i];

	ll ct = 0;
	for (int mask = 1; mask < (1 << k); mask++)
	{
		ll lcm = 1;
		int sign = -1;

		for (int bit = 0; bit < k; bit++)
		{
			if (mask & (1 << bit))
			{
				sign *= -1;
				if (lcm > n / a[bit])
				{
					lcm = n + 1;
					break;
				}
				else
					lcm *= a[bit];
			}
		}
		ct += sign * (n / lcm);
	}
	cout << ct;
}