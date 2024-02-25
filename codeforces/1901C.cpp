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
	int maxdiff = a[n - 1] - a[0];

	if (maxdiff == 0)
	{
		cout << 0 << endl;
		return;
	}

	int num = 0;
	while ((1 << num) <= maxdiff)
		num++;
	cout << num << endl;

	int down = a[0];
	if (num <= n)
	{
		for (int i = 0; i < num; i++)
		{
			int x = down % 2;
			cout << x << " ";
			down = (down + x) / 2;
		}
		cout << endl;
	}
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