#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
	FASTIO
	int n;
	cin >> n;
	ll a[n + 1], p[n + 1];

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i];
	};
	for (int i = 2; i <= n; i++)
		cin >> p[i];

	int steps[n + 1];
	steps[1] = 0;
	vector<ll> sumReached(n + 1, 0);

	for (int i = 2; i <= n; i++)
	{
		steps[i] = 1 + steps[p[i]];
		sumReached[steps[i]] += a[i];
	}

	int idx = -1;
	for (int i = n; i >= 1; i--)
	{
		if (sumReached[i] != 0)
		{
			idx = i;
			break;
		}
	}

	if (idx != -1)
	{
		if (sumReached[idx] > 0)
			cout << '+';
		else
			cout << '-';
	}
	else
	{
		if (a[1] > 0)
			cout << '+';
		else if (a[1] < 0)
			cout << '-';
		else
			cout << 0;
	}
}