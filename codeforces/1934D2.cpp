#include <bits/stdc++.h>
using namespace std;
// #define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

void solve()
{
	ll n;
	cin >> n;
	int bits = __builtin_popcountll(n);
	if (bits % 2 == 0)
	{
		cout << "first" << endl;
		for (int i = 62; i >= 0; i--)
		{
			ll x = 1LL << i;
			if ((bool)(n & x))
			{
				cout << x << " " << (n ^ x) << endl;
				break;
			}
		}
	}
	else
		cout << "second" << endl;

	while (1)
	{
		ll p1, p2;
		cin >> p1 >> p2;
		if (p1 == 0 && p2 == 0)
			return;

		if (__builtin_popcountll(p1) % 2 == 0)
			n = p1;
		else
			n = p2;

		for (int i = 62; i >= 0; i--)
		{
			ll x = 1LL << i;
			if ((bool)(n & x))
			{
				cout << x << " " << (n ^ x) << endl;
				break;
			}
		}
	}
}

int main()
{
	// FASTIO
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}