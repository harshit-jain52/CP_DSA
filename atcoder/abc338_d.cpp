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
	int x[m];

	for (int i = 0; i < m; i++)
		cin >> x[i];

	vector<ll> cost(n + 2, 0);

	for (int i = 1; i < m; i++)
	{
		int a = x[i - 1];
		int b = x[i];
		if (a > b)
			swap(a, b);

		cost[a] += n - (b - a);
		cost[b] -= n - (b - a);

		cost[1] += (b - a);
		cost[a] -= (b - a);
		cost[b] += (b - a);
	}

	ll ans = 1e15;
	for (int i = 1; i <= n; i++)
	{
		cost[i] += cost[i - 1];

		ans = min(ans, cost[i]);
	}

	cout << ans;
}