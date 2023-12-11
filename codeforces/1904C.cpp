#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

void solve()
{
	int n, k;
	cin >> n >> k;

	ll a[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	if (k >= 3)
	{
		cout << 0 << endl;
		return;
	}

	sort(a, a + n);

	ll diff = a[0];
	for (int i = 1; i < n; i++)
		diff = min(diff, a[i] - a[i - 1]);

	if (k == 1)
	{
		cout << diff << endl;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			ll d = a[j] - a[i];

			int x = lower_bound(a, a + n, d) - a;
			if (x < n)
				diff = min(diff, a[x] - d);
			if (x > 0)
				diff = min(diff, d - a[x - 1]);
		}
	}
	cout << diff << endl;
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