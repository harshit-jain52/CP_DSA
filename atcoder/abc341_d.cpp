#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef unsigned long long ll;
const int M = 1e9 + 7;

int main()
{
	FASTIO
	ll n, m, k;
	cin >> n >> m >> k;
	ll lcm = (m * n) / __gcd(m, n);
	ll lo = 0, hi = 2e18 + 5;
	ll mid;

	while (hi - lo > 1)
	{
		mid = (lo + hi) / 2;

		ll num1 = mid / n, num2 = mid / m, num3 = mid / lcm;
		ll num = num1 + num2 - 2 * num3;
		if (num < k)
			lo = mid;
		else
			hi = mid;
	}

	cout << hi;
}