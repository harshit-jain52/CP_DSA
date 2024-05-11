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
	if (a == 0 || a == 1)
		return a;
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
	ll n;
	cin >> n;
	int sum = 0;

	int mod_inv2 = binpow(2, M - 2);
	auto range_sum = [&](ll start, ll end) -> int
	{
		return ((((end - start + 1) % M) * ((start + end) % M) % M) * mod_inv2 % M);
	};

	// contribution of num = num*floor(n/num)
	// no. of distinct values of floor(n/i) for i:[1,N] = O(root(N))

	for (ll num = 1, last; num <= n; num = last + 1)
	{
		// value of floor(n/i) remains same in i:[num,last]
		ll weight = n / num;
		last = n / weight;
		sum = (sum + (range_sum(num, last) * 1LL * (weight % M)) % M) % M;
	}

	cout << sum;
}