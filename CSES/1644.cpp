#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const ll INF = 1e15;

int main()
{
	FASTIO
	int n, a, b;
	cin >> n >> a >> b;
	ll x[n + 1];
	x[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		int tmp;
		cin >> tmp;
		x[i] = tmp + x[i - 1];
	}

	ll ans = -INF;
	multiset<ll> st;
	for (int i = a; i <= n; i++)
	{
		if (i > b)
			st.erase(st.find(x[i - b - 1]));

		st.insert(x[i - a]);
		ans = max(ans, x[i] - *st.begin());
	}

	cout << ans;
}