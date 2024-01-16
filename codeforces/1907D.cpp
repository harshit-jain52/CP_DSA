#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

bool check(int n, ll l[], ll r[], ll k)
{
	ll minreach[n + 1], maxreach[n + 1];
	minreach[0] = maxreach[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		if (l[i] >= r[i - 1])
		{
			maxreach[i] = min(maxreach[i - 1] + k, r[i]);
			if (maxreach[i] < l[i])
				return false;
			minreach[i] = l[i];
		}
		else if (r[i] <= l[i - 1])
		{
			minreach[i] = max(l[i], minreach[i - 1] - k);
			if (minreach[i] > r[i])
				return false;
			maxreach[i] = r[i];
		}
		else if (r[i] >= r[i - 1] && l[i] <= l[i - 1])
		{
			maxreach[i] = min(r[i], maxreach[i - 1] + k);
			minreach[i] = max(l[i], minreach[i - 1] - k);
		}
		else
		{
			if (minreach[i - 1] > r[i])
			{
				minreach[i] = max(l[i], minreach[i - 1] - k);
				if (minreach[i] > r[i])
					return false;
				maxreach[i] = r[i];
			}
			else if (maxreach[i - 1] < l[i])
			{
				maxreach[i] = min(r[i], maxreach[i - 1] + k);
				if (maxreach[i] < l[i])
					return false;
				minreach[i] = l[i];
			}
			else
			{
				maxreach[i] = min(r[i], maxreach[i - 1] + k);
				minreach[i] = max(l[i], minreach[i - 1] - k);
			}
		}
	}
	return true;
}

void solve()
{
	int n;
	cin >> n;
	ll l[n + 1], r[n + 1];
	l[0] = r[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		cin >> l[i] >> r[i];
	}

	ll lo = 0, hi = *max_element(r, r + n + 1), mid;

	while (hi - lo > 1)
	{
		mid = (lo + hi) / 2;

		if (check(n, l, r, mid))
			hi = mid;
		else
			lo = mid + 1;
	}

	if (check(n, l, r, lo))
		cout << lo;
	else
		cout << hi;
	cout << endl;
}

int main()
{
	FASTIO
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}