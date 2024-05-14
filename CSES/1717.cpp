#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

int binpow(int a, int b)
{
	int ans = 1;
	while (b)
	{
		if (b & 1)
			ans = (ans * 1LL * a) % M;
		a = (a * 1LL * a) % M;
		b >>= 1;
	}
	return ans;
}

int main()
{
	FASTIO
	int n;
	cin >> n;

	int fact[n + 1], fact_inv[n + 1];
	fact[0] = fact_inv[0] = 1;

	for (int i = 1; i <= n; i++)
	{
		fact[i] = (fact[i - 1] * 1LL * i) % M;
		fact_inv[i] = binpow(fact[i], M - 2);
	}

	int ans = fact[n];
	int sign = -1;
	for (int i = 1; i <= n; i++)
	{
		int term = sign * (fact[n] * 1LL * fact_inv[i]) % M;
		if (term < 0)
			term += M;
		ans = (ans + term) % M;
		sign *= -1;
	}
	cout << ans;
}