#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 998244353;

int main()
{
	FASTIO
	int n, m;
	cin >> n >> m;
	string a, b;
	cin >> a >> b;
	int ct[m];
	ct[0] = (b[0] == '1');
	for (int i = 1; i < m; i++)
		ct[i] = ct[i - 1] + (b[i] == '1');

	int pow2[n];
	pow2[0] = 1;
	for (int i = 1; i < n; i++)
		pow2[i] = (pow2[i - 1] * 1LL * 2) % M;

	ll ans = 0;
	for (int i = m - 1; i >= 0; i--)
	{
		int idx = n - 1 - (m - 1 - i);
		if (idx < 0)
			break;
		int wt = pow2[n - 1 - idx];
		if (a[idx] == '1')
			ans = (ans + 0LL + (wt * 1LL * ct[i]) % M) % M;
	}

	cout << ans;
}