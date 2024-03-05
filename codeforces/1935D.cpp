#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef unsigned long long ll;
const int M = 1e9 + 7;

void solve()
{
	int n;
	ll c;
	cin >> n >> c;
	int s[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> s[i];

	int odd[n + 1], even[n + 1];
	odd[0] = even[0] = 1;

	for (int i = 1; i <= n; i++)
	{
		odd[i] = odd[i - 1] + s[i] % 2;
		even[i] = even[i - 1] + 1 - (s[i] % 2);
	}

	ll ct = (c + 1) * c / 2 + (c + 1);
	for (int i = 1; i <= n; i++)
	{
		ct -= (c + 1 - s[i]);
		ct -= (s[i] / 2 + 1);
		if (s[i] % 2 == 0)
			ct += even[i] - 1;
		else
			ct += odd[i] - 1;
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