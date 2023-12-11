#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

void solve()
{
	int n;
	cin >> n;
	ll a[n];
	set<ll> st;

	ll maxelem = INT_MIN;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		maxelem = max(a[i], maxelem);
		st.insert(a[i]);
	}

	if (n == 1)
	{
		cout << 1 << endl;
		return;
	}

	ll x = 0;
	for (int i = 0; i < n; ++i)
		x = __gcd(x, maxelem - a[i]);

	ll num = maxelem;
	while (st.find(num) != st.end())
	{
		num -= x;
	}

	ll ct = (maxelem - num) / x;
	for (int i = 0; i < n; ++i)
		ct += (maxelem - a[i]) / x;

	cout << ct << endl;
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