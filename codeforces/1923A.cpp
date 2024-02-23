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
	bool got1 = false;
	int ct = 0;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		if (tmp == 1)
		{
			got1 = true;
			ans += ct;
			ct = 0;
		}
		else if (got1)
			ct++;
	}

	cout << ans << endl;
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