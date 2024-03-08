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
	ll l, r;
	cin >> l >> r;

	int idx = -1;
	for (int i = 61; i >= 0; i--)
	{
		ll x = (1LL << i);
		bool L = (l & x), R = (r & x);
		if (R && !L)
		{
			idx = i;
			break;
		}
	}
	cout << ((1LL << (idx + 1)) - 1);
}