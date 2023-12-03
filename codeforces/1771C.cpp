#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;
const int N = sqrtf(1e9) + 5;

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

bool solve()
{
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	set<int> st;
	for (int i = 0; i < n; i++)
	{
		int num = a[i];
		for (auto it : primes)
		{
			if (it * 1LL * it > num)
				break;
			if (num <= 1)
				break;

			if (num % it == 0)
			{
				if (st.find(it) != st.end())
					return true;
				st.insert(it);

				while (num % it == 0)
				{
					num /= it;
				}
			}
		}

		if (num <= 1)
			continue;
		if (st.find(num) != st.end())
			return true;
		st.insert(num);
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sieve();
	int t;
	cin >> t;
	while (t--)
	{
		if (solve())
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
	}
}