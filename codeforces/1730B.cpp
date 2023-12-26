#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
typedef long double ld;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
const ld prec = 1e-6;
ld t[N], x[N];

bool func(ld time, int n)
{
	ld left = -1, right = 1e9 + 13;
	for (int i = 0; i < n; i++)
	{
		if (t[i] > time)
			return false;
		left = max(left, x[i] - (time - t[i]));
		right = min(right, x[i] + (time - t[i]));
	}

	return left <= right;
}

void solve()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> x[i];
	for (int i = 0; i < n; i++)
		cin >> t[i];

	ld lo = -1, hi = 1e9, mid;
	while (hi - lo > prec)
	{
		mid = (hi + lo) / 2.0;
		if (func(mid, n))
			hi = mid;
		else
			lo = mid;
	}

	ld time = hi;
	// cout << time << endl;
	ld left = -1, right = 1e9;
	for (int i = 0; i < n; i++)
	{
		left = max(left, x[i] - (time - t[i]));
		right = min(right, x[i] + (time - t[i]));
	}
	// cout << left << " "<<right<<endl;
	cout << left << endl;
}

int main()
{
	FASTIO
	int T;
	cin >> T;
	cout << setprecision(14);
	while (T--)
	{
		solve();
	}
}