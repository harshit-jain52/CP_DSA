#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;
const int N = 1e4 + 5;

vector<bool> isPrime(N, 1);
vector<int> primes;
void sieve()
{
	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i < N; i++)
	{
		if (isPrime[i] == true)
		{
			primes.push_back(i);
			for (int j = 2 * i; j < N; j += i)
				isPrime[j] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sieve();
	int n;
	cin >> n;
	while (n--)
	{
		int x, y;
		cin >> x >> y;

		if (__gcd(x, y) != 1)
		{
			cout << 0 << endl;
			continue;
		}

		int diff = abs(y - x);

		if (diff == 1)
		{
			cout << -1 << endl;
			continue;
		}

		if (diff % 2 == 0)
		{
			cout << 1 << endl;
			continue;
		}

		int ans = INT_MAX;
		for (auto it : primes)
		{
			if (it * 1LL * it > diff)
				break;
			if (diff <= 1)
				break;

			if (diff % it == 0)
			{
				if (x % it == y % it)
				{
					ans = min(ans, it - x % it);
				}
			}
			while (diff % it == 0)
			{
				diff /= it;
			}
		}
		if (diff > 1)
		{
			if (x % diff == y % diff)
			{
				ans = min(ans, diff - x % diff);
			}
		}

		cout << ans << endl;
	}
}