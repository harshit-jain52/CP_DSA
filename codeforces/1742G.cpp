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
	int maxidx, maxor = -1;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		if (a[i] > maxor)
		{
			maxor = a[i];
			maxidx = i;
		}
	}

	cout << a[maxidx] << " ";
	a[maxidx] = -1;

	for (int i = 1; i <= 32; ++i)
	{
		int last = maxor;
		maxidx = -1;
		for (int j = 0; j < n; j++)
		{
			if (a[j] != -1 && (last | a[j]) >= maxor)
			{
				maxor = (last | a[j]);
				maxidx = j;
			}
		}
		if (maxidx != -1)
		{
			cout << a[maxidx] << " ";
			a[maxidx] = -1;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		if (a[i] != -1)
			cout << a[i] << " ";
	}

	cout << endl;
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