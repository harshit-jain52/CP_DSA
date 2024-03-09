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
	int pos[n];
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		pos[a] = i;
	}

	if (n <= 2)
	{
		cout << 1 << endl;
		return;
	}

	ll ct = 1;
	int l = pos[1], r = pos[0];
	if (l > r)
		swap(l, r);
	for (int i = 2; i < n; i++)
	{
		if (pos[i] < l)
			l = pos[i];
		else if (pos[i] > r)
			r = pos[i];
		else
		{
			ll len = r - l + 1;
			ct = (ct * (len - i)) % M;
		}
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