#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

bool solve()
{
	ll n, x, p;
	cin >> n >> x >> p;

	/*
	for a number n, all remainders are possible remainders resulting from
	f*(f+1)/2 are covered from f=1 to f=2n
	*/

	for (ll f = 1; f <= min(2 * n, p); f++)
	{
		if ((x + f * (f + 1) / 2) % n == 0)
			return true;
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
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