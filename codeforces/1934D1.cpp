#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef unsigned long long ll;
const int M = 1e9 + 7;

void solve()
{
	ll m, n;
	cin >> n >> m;
	ll x = n ^ m;

	if (x < n)
	{
		cout << 1 << endl;
		cout << n << " " << m << endl;
		return;
	}

	int found1 = -1, found2 = -1;
	for (int i = 62; i >= 0; i--)
	{
		x = (1LL << i);
		if ((bool)(x & n))
		{
			if (found1 == -1)
			{
				found1 = i;
				continue;
			}
			else
			{
				found2 = i;
				break;
			}
		}
		if ((bool)(x & m))
		{
			cout << -1 << endl;
			return;
		}
	}

	ll num = (1LL << found1);
	for (int i = found2 - 1; i >= 0; i--)
	{
		x = (1LL << i);
		if ((bool)(x & m) != (bool)(x & n))
			num += x;
	}

	cout << 2 << endl;
	cout << n << " " << (n ^ num) << " " << m << endl;
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