#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

void solve()
{
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	if (k > 1)
	{
		cout << "YES" << endl;
		return;
	}

	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] > a[i + 1])
		{
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
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