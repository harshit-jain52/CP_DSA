#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 998244353;

void solve()
{
	int l, r;
	cin >> l >> r;
	int len = r - l + 1;
	if (l % 2 == 0 && len % 2 == 1)
	{
		cout << -1 << endl;
		return;
	}

	if (len % 2 == 1)
	{
		cout << l + 1 << " " << l + 2 << " " << l << " ";
		for (int i = 3; i < len; i += 2)
			cout << l + i + 1 << " " << l + i << " ";
	}
	else
	{
		for (int i = 0; i < len; i += 2)
			cout << l + i + 1 << " " << l + i << " ";
	}
	cout << endl;
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