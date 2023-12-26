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
	vector<pair<ll, int>> a;
	bool zeroPresent = false;
	int neg = 0;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		zeroPresent |= (tmp == 0);
		neg += (tmp < 0);
		a.push_back({tmp, i + 1});
	}

	if (zeroPresent || neg % 2 == 1)
	{
		cout << 0 << endl;
		return;
	}

	cout << 1 << endl;
	cout << 1 << " " << 0 << endl;
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