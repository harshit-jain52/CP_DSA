#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

bool solve()
{
	int n;
	cin >> n;
	ll a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 1; i < n - 1; i++)
	{
		a[i] -= 2 * a[i - 1];
		a[i + 1] -= a[i - 1];
		a[i - 1] = 0;
		if (a[i] < 0 || a[i + 1] < 0)
			return false;
	}
	return (a[n - 1] == 0 && a[n - 2] == 0);
}

int main()
{
	FASTIO
	int t;
	cin >> t;
	while (t--)
	{
		if (solve())
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
	}
}