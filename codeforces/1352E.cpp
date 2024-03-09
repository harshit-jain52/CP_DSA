#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);

void solve()
{
	short n;
	cin >> n;
	int pref[n + 1];
	pref[0] = 0;
	bool b[n + 1];
	for (int i = 1; i <= n; i++)
	{
		cin >> pref[i];
		b[i] = false;
	}

	for (int i = 1; i <= n; i++)
		pref[i] += pref[i - 1];

	for (int l = 1; l < n; l++)
	{
		for (int r = l + 1; r <= n; r++)
		{
			if (pref[r] - pref[l - 1] <= n)
				b[pref[r] - pref[l - 1]] = true;
		}
	}

	short ct = 0;
	for (int i = 1; i <= n; i++)
	{
		if (b[pref[i] - pref[i - 1]])
			ct++;
	}
	cout << ct << endl;
}

int main()
{
	FASTIO
	short t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}