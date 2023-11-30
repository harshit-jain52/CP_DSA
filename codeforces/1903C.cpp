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
		cin >> a[i];
	}

	ll suff[n];
	suff[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		suff[i] = suff[i + 1] + a[i];
	}

	ll ans = 0;
	ll num = 1, tmpsum = 0;
	for (int i = 0; i < n - 1; i++)
	{
		tmpsum += a[i];
		if (suff[i + 1] > 0 || (suff[i + 1] == 0 && a[i + 1] > 0))
		{
			ans += num * tmpsum;
			num++;
			tmpsum = 0;
		}
	}
	tmpsum += a[n - 1];
	ans += num * tmpsum;
	cout << ans << endl;
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