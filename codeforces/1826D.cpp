#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

void solve()
{
	int n;
	cin >> n;
	ll b[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> b[i];
	}

	ll distOfLeft[n], distOfRight[n];
	for (int i = 0; i < n; i++)
	{
		distOfLeft[i] = b[i] - (n - 1 - i);
		distOfRight[i] = b[i] - i;
	}

	ll maxfromright[n], maxfromleft[n];
	maxfromright[n - 1] = distOfRight[n - 1], maxfromleft[0] = distOfLeft[0];
	for (int i = 1; i < n; i++)
	{
		maxfromright[n - 1 - i] = max(maxfromright[n - i], distOfRight[n - 1 - i]);
		maxfromleft[i] = max(maxfromleft[i - 1], distOfLeft[i]);
	}

	ll ans = INT_MIN;
	for (int i = 1; i < n - 1; i++)
	{
		ans = max(ans, maxfromleft[i - 1] + (n - 1 - i) + maxfromright[i + 1] + i + b[i]);
	}

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