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
	ll w[n];
	for (int i = 0; i < n; i++)
		cin >> w[i];

	ll maxw = 0;
	sort(w, w + n);

	for (int i = n - 1; i >= 0; i--)
	{
		maxw = max(maxw, w[i] * (n - i));
	}

	cout << maxw << endl;
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