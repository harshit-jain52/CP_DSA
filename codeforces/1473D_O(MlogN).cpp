#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e7;
int pref[N], maxseg[4 * N], minseg[4 * N];

void build(int idx, int lo, int hi)
{
	if (lo > hi)
		return;
	if (lo == hi)
	{
		maxseg[idx] = pref[lo];
		minseg[idx] = pref[lo];
		return;
	}

	int mid = (lo + hi) / 2;
	build(2 * idx + 1, lo, mid);
	build(2 * idx + 2, mid + 1, hi);

	maxseg[idx] = max(maxseg[2 * idx + 1], maxseg[2 * idx + 2]);
	minseg[idx] = min(minseg[2 * idx + 1], minseg[2 * idx + 2]);
}

int range_max(int idx, int lo, int hi, int l, int r)
{
	if (r < lo || l > hi)
		return -INF;

	if (lo >= l && hi <= r)
		return maxseg[idx];

	int mid = (lo + hi) / 2;

	return max(range_max(2 * idx + 1, lo, mid, l, r), range_max(2 * idx + 2, mid + 1, hi, l, r));
}

int range_min(int idx, int lo, int hi, int l, int r)
{
	if (r < lo || l > hi)
		return INF;

	if (lo >= l && hi <= r)
		return minseg[idx];

	int mid = (lo + hi) / 2;

	return min(range_min(2 * idx + 1, lo, mid, l, r), range_min(2 * idx + 2, mid + 1, hi, l, r));
}

void solve()
{
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;

	pref[0] = 0;
	for (int i = 0; i < n; i++)
		pref[i + 1] = pref[i] + ((s[i] == '+') ? 1 : -1);

	build(0, 0, n);

	while (m--)
	{
		int l, r, upper, lower;
		cin >> l >> r;
		upper = max(0, max(range_max(0, 0, n, 0, l - 1), pref[l - 1] + range_max(0, 0, n, r + 1, n) - pref[r]));
		lower = min(0, min(range_min(0, 0, n, 0, l - 1), pref[l - 1] + range_min(0, 0, n, r + 1, n) - pref[r]));
		cout << 1 + upper - lower << endl;
	}
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