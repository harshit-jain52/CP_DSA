#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 998244353;
const int N = 1e5;

vector<bool> isPrime(N, 1);
vector<int> primes;
void sieve()
{
	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i < N; i++)
	{
		if (isPrime[i] == true)
		{
			for (int j = 2 * i; j < N; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
}

int binExp(int a, int b)
{
	if (b == 0)
		return 1;

	int res = binExp(a, b / 2);

	if (b % 2 == 0)
		return (res * 1LL * res) % M;
	else
		return (a * 1LL * ((res * 1LL * res) % M) % M);
}

void solve()
{
	int n, x;
	cin >> n >> x;
	vector<int> v;
	for (int num : primes)
	{
		if (num * num > x)
			break;
		int ct = 0;
		while (x % num == 0)
		{
			ct++;
			x /= num;
		}
		if (ct)
			v.push_back(ct);
	}
	if (x != 1)
		v.push_back(1);

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int prod = 1;
		for (int ct : v)
		{
			prod = (prod * 1LL * (binExp(ct + 1, i) - binExp(ct, i) + M)) % M;
		}
		ans = (ans + prod) % M;
	}
	cout << ans << endl;
}

int main()
{
	FASTIO
	sieve();

	for (int i = 2; i < N; i++)
	{
		if (isPrime[i])
			primes.push_back(i);
	}
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}