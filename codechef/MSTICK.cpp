#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int N = 1e5 + 5;
const int LOG = 17;

ll mn[N][LOG], mx[N][LOG];
int binLog[N];
int n;

ll query(int L, int R)
{
	int k = binLog[R - L + 1];
	ll x = min(mn[L][k], mn[R - (1 << k) + 1][k]);
	ll y = max(mx[L][k], mx[R - (1 << k) + 1][k]);
	ll y1 = 0, y2 = 0;
	if (L > 0)
		y1 = max(mx[0][binLog[L]], mx[L - 1 - (1 << binLog[L]) + 1][binLog[L]]);
	if (R < n - 1)
		y2 = max(mx[R + 1][binLog[n - R - 1]], mx[n - 1 - (1 << binLog[n - R - 1]) + 1][binLog[n - R - 1]]);
	ll diff = y - x;
	return 2 * x + max({y - x, 2 * y1, 2 * y2});
}

int main()
{
	FASTIO
	cin >> n;

	binLog[1] = 0;
	for (int i = 2; i <= n; i++)
		binLog[i] = binLog[i / 2] + 1;

	int b[n];
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
		mn[i][0] = mx[i][0] = b[i];
	}

	for (int j = 1; j <= binLog[n]; j++)
	{
		for (int i = 0; i + (1 << j) - 1 < n; i++)
		{
			mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
			mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
		}
	}

	int q;
	cin >> q;
	while (q--)
	{
		int l, r;
		cin >> l >> r;
		ll twice = query(l, r);
		cout << twice / 2 << "." << ((twice & 1) ? 5 : 0) << endl;
	}
}