#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
	FASTIO
	int n, m;
	cin >> n >> m;

	if (n > m + 1 || m > 2 * n + 2)
	{
		cout << -1;
		return 0;
	}

	if (n > m)
	{
		cout << 0;
		n--;
	}
	while (m != n && m && n)
	{
		cout << 1 << 1 << 0;
		m -= 2;
		n -= 1;
	}

	while (m > 0 || n > 0)
	{
		if (m > 0)
			cout << 1;
		if (n > 0)
			cout << 0;
		m--;
		n--;
	}
}