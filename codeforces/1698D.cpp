#include <bits/stdc++.h>
using namespace std;
// #define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

void solve()
{
	int n;
	cin >> n;
	int lo = 1, hi = n;
	int l, r;
	while (1)
	{
		l = lo, r = (lo + hi) / 2;
		cout << "? " << l << " " << r << endl;
		int len = r - l + 1;
		int out = 0;
		for (int i = 0; i < len; i++)
		{
			int tmp;
			cin >> tmp;
			if (tmp < l || tmp > r)
				out++;
		}

		if (len == 1 && out == 0)
		{
			cout << "! " << l << endl;
			break;
		}
		if (len % 2 == out % 2)
			lo = r + 1;
		else
			hi = r;
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}