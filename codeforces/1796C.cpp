#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 998244353;

void solve()
{
	int l, r;
	cin >> l >> r;
	int x = r / l;
	ll num = 1;
	while ((1 << num) <= x)
	{
		num++;
	}

	ll fact = 1 << (num - 1);
	ll start = l, end = r / fact;
	ll ct = end - start + 1;

	fact = (fact * 3 / 2);
	end = r / fact;
	if (end >= start)
	{
		ct = (ct + ((end - start + 1) * (num - 1)) % M) % M;
	}

	cout << num << " " << ct << endl;
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