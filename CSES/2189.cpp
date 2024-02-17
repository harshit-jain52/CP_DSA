#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

ll solve()
{
	ll x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	ll ux = x1 - x3, uy = y1 - y3, vx = x2 - x3, vy = y2 - y3;

	return ux * vy - uy * vx;
}

int main()
{
	FASTIO
	int t;
	cin >> t;
	while (t--)
	{
		ll pos = solve();
		if (pos < 0)
			cout << "RIGHT";
		else if (pos > 0)
			cout << "LEFT";
		else
			cout << "TOUCH";
		cout << endl;
	}
}