#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

void solve()
{
	ll a, b, r;
	cin >> a >> b >> r;

	int mark = -1;

	for (int i = 60; i >= 0; i--)
	{
		ll pow = 1LL << i;
		if ((pow & a) == (pow & b))
			continue;
		mark = i;
		if (b & pow)
			swap(a, b);
		break;
	}

	ll num = 0;
	for (int i = mark - 1; i >= 0; i--)
	{
		ll pow = 1LL << i;
		if ((pow & a) == (pow & b))
			continue;
		if ((a & pow) && num + pow < r)
			num += pow;
	}

	cout << (a ^ num) - (b ^ num) << endl;
}

int main()
{
	FASTIO
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}