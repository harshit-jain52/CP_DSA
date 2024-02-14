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
	int n;
	cin >> n;
	vector<pair<ll, int>> sum;
	ll a[n], b[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];

	for (int i = 0; i < n; i++)
		sum.push_back({-(a[i] + b[i]), i});

	sort(sum.begin(), sum.end());

	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			ans += (a[sum[i].second] - 1);
		else
			ans -= (b[sum[i].second] - 1);
	}

	cout << ans << endl;
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