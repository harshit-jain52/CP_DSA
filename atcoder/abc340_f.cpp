#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
#define pll pair<ll, ll>
const int M = 1e9 + 7;

pll eeRecur(ll a, ll b)
{
	if (b == 0)
		return make_pair(1, 0);

	ll x, y;
	tie(y, x) = eeRecur(b, a % b);
	y -= a / b * x;

	return make_pair(x, y);
}

int main()
{
	FASTIO
	ll x, y;
	cin >> x >> y;

	// |ay - bx| = 2

	ll g = __gcd(x, y);
	if (abs(g) > 2)
	{
		cout << -1;
		return 0;
	}

	ll a, b;
	tie(a, b) = eeRecur(y, -x);

	cout << a * 2 / g << " " << b * 2 / g;
}