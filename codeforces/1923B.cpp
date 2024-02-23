#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int INF = 1e7;
bool solve()
{
	int n;
	ll k;
	cin >> n >> k;
	ll a[n + 2];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int x[n + 2];
	for (int i = 1; i <= n; i++)
		cin >> x[i];
	x[0] = -INF;
	x[n + 1] = INF;

	int t = 0;
	int pos = upper_bound(x, x + n + 2, 0) - x;
	int neg = pos - 1;
	// cout << neg << " "<<pos<<" ";
	while (neg > 0 || pos <= n)
	{
		ll negdist = abs(x[neg]) - t;
		ll posdist = x[pos] - t;
		if (negdist == 0 || posdist == 0)
			return false;

		ll rem = k;
		while (rem > 0 && (neg > 0 || pos <= n))
		{
			if (abs(x[neg]) < x[pos])
			{
				ll reduce = min(a[neg], rem);
				a[neg] -= reduce;
				rem -= reduce;
				if (a[neg] == 0)
					neg--;
			}
			else
			{
				ll reduce = min(a[pos], rem);
				a[pos] -= reduce;
				rem -= reduce;
				if (a[pos] == 0)
					pos++;
			}
		}
		t++;
	}
	return true;
}

int main()
{
	FASTIO
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