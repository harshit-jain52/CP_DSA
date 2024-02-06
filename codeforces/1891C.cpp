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
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	ll ans = 0, x = 0;
	int i = 0, j = n - 1;

	while (i < j)
	{
		if (x + a[i] >= a[j])
		{
			ans += (a[j] + 1);
			a[i] -= (a[j] - x);
			x = 0;
			j--;
		}
		else
		{
			x += a[i];
			i++;
		}
	}

	ans += (x + a[i]) / 2 + ((x + a[i]) / 2 > 0) + (x + a[i]) % 2;
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