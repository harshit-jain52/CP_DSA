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
	int n, k, d;
	cin >> n >> k >> d;
	int a[n], v[k];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < k; i++)
		cin >> v[i];

	int lim = min(d, 2 * n);

	int ans = 0;
	for (int day = 1; day <= lim; day++)
	{
		int ct = 0;
		for (int i = 0; i < n; i++)
			ct += (a[i] == (i + 1));

		ans = max(ans, ct + (d - day) / 2);
		for (int i = 0; i < v[(day - 1) % k]; i++)
			a[i]++;
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