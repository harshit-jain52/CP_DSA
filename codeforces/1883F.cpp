#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

void solve()
{
	int n;
	cin >> n;
	int a[n];
	map<int, int> rightmost, leftmost;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		rightmost[a[i]] = i;
	}
	for (int i = n - 1; i >= 0; i--)
	{
		leftmost[a[i]] = i;
	}

	ll pref[n];
	pref[0] = (leftmost[a[0]] == 0);
	for (int i = 1; i < n; i++)
	{
		pref[i] = pref[i - 1] + (leftmost[a[i]] == i);
	}

	ll ans = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (rightmost[a[i]] == i)
			ans += pref[i];
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