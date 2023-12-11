#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

set<ll> findDivisors(ll n)
{
	set<ll> divis;
	for (ll i = 1; i <= sqrtf(n); i++)
	{
		if (n % i == 0)
		{
			divis.insert(i);
			divis.insert(n / i);
		}
	}

	return divis;
}

void solve()
{
	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	if ((c * d) % (a * b) == 0)
	{
		cout << c << " " << d << endl;
		return;
	}

	set<ll> divisA = findDivisors(a);
	set<ll> divisB = findDivisors(b);

	set<ll> divisAB;
	for (ll diva : divisA)
	{
		for (ll divb : divisB)
		{
			divisAB.insert(diva * divb);
		}
	}

	for (ll x : divisAB)
	{

		ll num = a * b / x;

		ll y = (d / num) * num;
		if (x > a && x <= c && y > b)
		{
			cout << x << " " << y << endl;
			return;
		}

		y = (c / num) * num;
		if (x > b && x <= d && y > a)
		{
			cout << y << " " << x << endl;
			return;
		}
	}

	cout << -1 << " " << -1 << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}