#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 998244353;

void solve()
{
	int l, r;
	cin >> l >> r;
	int len = r - l + 1;
	if (__gcd(l, r) != 1 && len % 2 == 1)
	{
		cout << -1 << endl;
		return;
	}

	if (len % 2 == 1)
	{
		for (int i = l + 1; i <= r; i++)
			cout << i << " ";
		cout << l << endl;
	}
	else
	{
		for (int i = 0; i < len; i++)
		{
			if (i % 2 == 1)
				cout << l + i - 1 << " ";
			else
				cout << l + i + 1 << " ";
		}
		cout << endl;
	}
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