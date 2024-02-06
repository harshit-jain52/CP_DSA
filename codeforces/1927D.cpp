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
int arr[N];
pair<int, int> maxseg[4 * N], minseg[4 * N];

void build(int idx, int lo, int hi)
{
	if (lo > hi)
		return;

	if (lo == hi)
	{
		minseg[idx] = maxseg[idx] = make_pair(arr[lo], lo);
		return;
	}

	int mid = (lo + hi) / 2;
	build(2 * idx + 1, lo, mid);
	build(2 * idx + 2, mid + 1, hi);

	maxseg[idx] = max(maxseg[2 * idx + 1], maxseg[2 * idx + 2]);
	minseg[idx] = min(minseg[2 * idx + 1], minseg[2 * idx + 2]);
}

pair<int, int> range_max(int idx, int lo, int hi, int l, int r) // O(logN)
{
	if (r < lo || l > hi)
		return make_pair(-INF, -1);

	if (lo >= l && hi <= r)
		return maxseg[idx];

	int mid = (lo + hi) / 2;

	return max(range_max(2 * idx + 1, lo, mid, l, r), range_max(2 * idx + 2, mid + 1, hi, l, r));
}

pair<int, int> range_min(int idx, int lo, int hi, int l, int r) // O(logN)
{
	if (r < lo || l > hi)
		return make_pair(INF, -1);

	if (lo >= l && hi <= r)
		return minseg[idx];

	int mid = (lo + hi) / 2;

	return min(range_min(2 * idx + 1, lo, mid, l, r), range_min(2 * idx + 2, mid + 1, hi, l, r));
}

void solve()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	build(0, 0, n - 1);

	int q;
	cin >> q;
	while (q--)
	{
		int l, r;
		cin >> l >> r;
		auto up = range_max(0, 0, n - 1, l - 1, r - 1);
		auto down = range_min(0, 0, n - 1, l - 1, r - 1);

		if (up.first == down.first)
			cout << -1 << " " << -1 << endl;
		else
			cout << down.second + 1 << " " << up.second + 1 << endl;
	}
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