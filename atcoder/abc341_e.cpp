#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int N = 5e5 + 10;

ll arr[N];
ll seg[4 * N];

void build(int idx, int lo, int hi)
{
	if (lo > hi)
		return;
	if (lo == hi)
	{
		seg[idx] = arr[lo];
		return;
	}

	int mid = (lo + hi) / 2;

	build(2 * idx + 1, lo, mid);
	build(2 * idx + 2, mid + 1, hi);

	seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
}

ll range_sum(int idx, int lo, int hi, int l, int r)
{
	if (r < lo || l > hi)
		return 0;

	if (lo >= l && hi <= r)
		return seg[idx];

	int mid = (lo + hi) / 2;

	return range_sum(2 * idx + 1, lo, mid, l, r) + range_sum(2 * idx + 2, mid + 1, hi, l, r);
}

void point_update(int idx, int lo, int hi, int i)
{
	if (i < lo || i > hi)
		return;

	if (lo == hi)
	{
		seg[idx] = 1 - seg[idx];
		return;
	}

	int mid = (lo + hi) / 2;

	if (i <= mid)
		point_update(2 * idx + 1, lo, mid, i);
	else
		point_update(2 * idx + 2, mid + 1, hi, i);

	seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
}
int main()
{
	FASTIO
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;

	if (n == 1)
	{
		while (q--)
		{
			int type, l, r;
			cin >> type >> l >> r;
			if (type == 2)
				cout << "Yes" << endl;
		}

		return 0;
	}

	for (int i = 0; i < n - 1; i++)
		arr[i] = (s[i] != s[i + 1]);

	build(0, 0, n - 2);
	while (q--)
	{
		int type, l, r;
		cin >> type >> l >> r;

		if (type == 1)
		{
			point_update(0, 0, n - 2, l - 2);
			point_update(0, 0, n - 2, r - 1);
		}
		else
		{
			ll sum = range_sum(0, 0, n - 2, l - 1, r - 2);
			if (sum < r - l)
				cout << "No" << endl;
			else
				cout << "Yes" << endl;
		}
	}
}