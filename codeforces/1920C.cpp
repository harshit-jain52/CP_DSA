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

	int ct = 0;
	set<int> factors;
	for (int k = 1; k * k <= n; k++)
	{
		if (n % k == 0)
		{
			factors.insert(k);
			factors.insert(n / k);
		}
	}

	for (int k : factors)
	{
		int g = 0;
		for (int i = k; i < n; i++)
		{
			g = __gcd(g, abs(a[i] - a[i - k]));
		}
		if (g != 1)
			ct++;
	}
	cout << ct << endl;
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