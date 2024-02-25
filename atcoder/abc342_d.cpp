#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int N = 2e5 + 5;
vector<bool> isPrime(N, 1);
vector<int> hp(N, 0);

void highestPrimeFactor()
{
	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i < N; i++)
	{
		if (isPrime[i] == true)
		{
			hp[i] = i;
			for (int j = 2 * i; j < N; j += i)
			{
				isPrime[j] = false;
				hp[j] = i;
			}
		}
	}
}

int main()
{
	FASTIO
	highestPrimeFactor();
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	map<int, int> mp;

	int ct0 = 0;
	for (int i = 0; i < n; i++)
		ct0 += (a[i] == 0);

	ll ans = ct0 * 1LL * (n - ct0) + ct0 * 1LL * (ct0 - 1) / 2;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 0)
			continue;

		int oddprod = 1;
		int num = a[i];

		while (num > 1)
		{
			int pf = hp[num];
			int ct = 0;
			while (num % pf == 0)
			{
				ct++;
				num /= pf;
			}
			if (ct % 2 == 1)
				oddprod *= pf;
		}

		ans += mp[oddprod];
		mp[oddprod]++;
	}

	cout << ans;
}