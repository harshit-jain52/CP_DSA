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
	ll a[n + 1], b[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> b[i];

	ll exp[n + 1];
	exp[1] = a[1] - min(a[1], b[n]);
	for (int i = 2; i <= n; i++)
		exp[i] = a[i] - min(a[i], b[i - 1]);

	ll start1 = a[1];
	for (int i = 2; i <= n; i++)
		start1 += exp[i];

	ll ans = start1;
	for (int i = 2; i <= n; i++)
		ans = min(ans, start1 - a[1] + exp[1] + a[i] - exp[i]);

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