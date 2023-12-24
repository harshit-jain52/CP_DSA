#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

ll solve()
{
	int n;
	cin >> n;
	ll a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	ll num = 2;
	set<ll> st;

	while (1)
	{
		for (int i = 0; i < n; i++)
		{
			st.insert(a[i] % num);
		}
		if (st.size() == 2)
			return num;
		st.clear();
		num *= 2;
	}
}

int main()
{
	FASTIO
	int t;
	cin >> t;
	while (t--)
	{
		cout << solve() << endl;
	}
}