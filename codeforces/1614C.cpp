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
	int n, m;
	cin >> n >> m;
	ll or_all = 0;
	while (m--)
	{
		int l, r;
		ll x;
		cin >> l >> r >> x;
		or_all |= x;
	}

	// 2^(n-1)
	int pow = 1;
	for (int i = 1; i < n; i++)
		pow = (pow * 1LL * 2) % M;

	int sum_set = 0;
	for (int i = 0; i <= 30; i++)
		sum_set = (sum_set + ((1 << i) & or_all)) % M;

	cout << (sum_set * 1LL * pow) % M << endl;
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