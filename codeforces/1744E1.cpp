#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

void solve()
{
	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	for (ll x = a + 1; x <= c; x++)
	{
		ll num = a * b / __gcd(a * b, x);
		ll y = (d / num) * num;
		if (y > b)
		{
			cout << x << " " << y << endl;
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