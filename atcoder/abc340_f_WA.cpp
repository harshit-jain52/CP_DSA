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
	ll x, y;
	cin >> x >> y;

	x = abs(x);
	y = abs(y);

	if (x != 0 && y != 0 && __gcd(x, y) > 1)
	{
		cout << -1;
		return 0;
	}

	if (x == 0)
	{
		if (y == 2)
			cout << 1 << " " << 1;
		else if (y == 1)
			cout << 2 << " " << 1;
		else
			cout << -1;
		return 0;
	}
	if (y == 0)
	{
		if (x == 2)
			cout << 1 << " " << 1;
		else if (x == 1)
			cout << 1 << " " << 2;
		else
			cout << -1;
		return 0;
	}

	for (ll num = 1; num * x <= 1e18 && num * num <= y; num++)
	{
		if (__gcd(num, y) != 1)
			continue;

		if ((num * x - 1) % y == 0)
		{
			cout << 2 * (num * x - 1) / y << " " << 2 * num;
			return 0;
		}
		if ((num * x + 1) % y == 0)
		{
			cout << 2 * (num * x + 1) / y << " " << 2 * num;
			return 0;
		}
	}
}