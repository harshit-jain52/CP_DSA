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
	int n, q;
	cin >> n >> q;
	ll r[n];
	for (int i = 0; i < n; i++)
		cin >> r[i];

	sort(r, r + n);
	for (int i = 1; i < n; i++)
		r[i] += r[i - 1];

	while (q--)
	{
		ll x;
		cin >> x;
		int num = upper_bound(r, r + n, x) - r;
		cout << num << endl;
	}
}