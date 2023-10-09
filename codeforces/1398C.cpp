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
	for (int i = 0; i < n; ++i)
	{
		char c;
		cin >> c;
		a[i] = c - '0';
	}

	ll prefix_sum[n + 1];
	prefix_sum[0] = 0;

	for (int i = 0; i < n; ++i)
	{
		prefix_sum[i + 1] = prefix_sum[i] + a[i];
	}

	// p[r] - p[l-1] = r - (l-1)
	// p[r] - r = p[l-1] - l

	map<ll, ll> m;
	ll ct = 0;
	for (int i = 0; i <= n; ++i)
	{
		ct += m[prefix_sum[i] - i];
		m[prefix_sum[i] - i]++;
	}

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