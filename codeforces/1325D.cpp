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
	ll x, s;
	cin >> x >> s;

	// A+B = A^B + 2*(A&B)

	if (s < x || ((s - x) & 1))
		cout << -1;
	else if (s == x)
	{
		if (x == 0)
			cout << 0;
		else
			cout << 1 << endl
				 << x;
	}
	else
	{
		ll diff = s - x;
		ll an = diff / 2; // A&B
		if (an & x)
		{
			// there can't be A,B such that A^B=x and A&B=an
			cout << 3 << endl;
			cout << x << " " << an << " " << an;
		}
		else
		{
			cout << 2 << endl;
			cout << x + an << " " << an; // x+an = x|an
		}
	}
}