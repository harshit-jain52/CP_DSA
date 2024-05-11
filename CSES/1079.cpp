#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int N = 1e6 + 1;
int fact[N];

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

int nCr(int n, int r)
{
	if (r == 0 || r == n)
		return 1;

	int ans = (fact[n] * 1LL * ((binpow(fact[r], M - 2) * 1LL * binpow(fact[n - r], M - 2)) % M)) % M;
	return ans;
}

int main()
{
	FASTIO
	fact[0] = 1;
	for (int i = 1; i < N; i++)
		fact[i] = (fact[i - 1] * 1LL * i) % M;

	int n;
	cin >> n;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		cout << nCr(a, b) << endl;
	}
}