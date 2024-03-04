#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int N = 2e5 + 10;
vector<bool> isPrime(N, 1);

void sieve()
{
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i < N; i++)
	{
		if (isPrime[i] == true)
		{
			for (int j = 2 * i; j < N; j += i)
				isPrime[j] = false;
		}
	}
}

int main()
{
	FASTIO
	sieve();

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	if (n == 2)
	{
		cout << a[0] * 1LL * a[1] / __gcd(a[0], a[1]);
		return 0;
	}
	int mx = *max_element(a, a + n);
	vector<int> primes;
	for (int i = 2; i <= mx; i++)
		if (isPrime[i])
			primes.push_back(i);

	int g = 1;

	for (int p : primes)
	{
		int min1 = 32, min2 = 32;
		for (int i = 0; i < n; i++)
		{
			int ct = 0;
			while (a[i] % p == 0)
			{
				a[i] /= p;
				ct++;
			}

			if (ct < min1)
			{
				min2 = min1;
				min1 = ct;
			}
			else if (ct < min2)
			{
				min2 = ct;
			}

			if (min1 == 0 && min2 == 0)
				break;
		}

		int mul = 1;
		for (int j = 1; j <= min2; j++)
			mul *= p;
		g *= mul;
	}

	cout << g << endl;
}