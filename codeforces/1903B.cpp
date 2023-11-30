#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

void solve()
{
	int n;
	cin >> n;

	int m[n][n];
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		a[i] = (1 << 30) - 1;
		for (int j = 0; j < n; ++j)
		{
			cin >> m[i][j];
			if (i != j)
				a[i] &= m[i][j];
		}
	}

	bool flag = true;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i != j)
			{
				if ((a[i] | a[j]) != m[i][j])
				{
					flag = false;
					break;
				}
			}
		}
	}

	if (flag)
	{
		cout << "YES" << endl;
		for (int i = 0; i < n; i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;
	}
	else
		cout << "NO" << endl;

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