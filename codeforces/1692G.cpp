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
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int len = 1, ct = 0;
	for (int i = 1; i < n; i++)
	{
		if (2 * a[i] > a[i - 1])
			len++;
		else
			len = 1;

		if (len > k)
			ct++;
	}

	cout << ct << endl;
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