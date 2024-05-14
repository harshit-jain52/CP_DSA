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

int nCr(int n, int r)
{
	r = min(r, n - r);
	if (r == 0)
		return 1;
	int ans = 1;
	for (int i = 0; i < r; i++)
	{
		ans = (ans * 1LL * (n - i)) % M;
		ans = (ans * 1LL * binpow(i + 1, M - 2)) % M;
	}
	return ans;
}

int main()
{
	FASTIO
	int n, m;
	cin >> n >> m;
	cout << nCr(n + m - 1, n - 1);
}