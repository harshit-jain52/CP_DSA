#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

set<ll> st;

int main()
{
	FASTIO
	int n, m, l, q;
	cin >> n;
	ll a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> m;
	ll b[m];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	cin >> l;
	ll c[l];
	for (int i = 0; i < l; i++)
		cin >> c[i];
	cin >> q;
	ll x[q];
	for (int i = 0; i < q; i++)
		cin >> x[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < l; k++)
			{
				st.insert(a[i] + b[j] + c[k]);
			}
		}
	}

	for (int i = 0; i < q; i++)
	{
		if (st.find(x[i]) != st.end())
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}