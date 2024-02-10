#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

map<ll, ll> mp;

ll cost(ll n)
{
	if (n < 2)
		return 0;

	if (mp.find(n) != mp.end())
		return mp[n];

	ll res = n;
	if (n % 2 == 0)
		res += 2 * cost(n / 2);
	else
		res += cost(n / 2) + cost(n / 2 + 1);

	return mp[n] = res;
}

int main()
{
	ll n;
	cin >> n;
	cout << cost(n);
}