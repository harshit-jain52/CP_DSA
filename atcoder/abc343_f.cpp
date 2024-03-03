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
int arr[N];
array<int, 4> seg[4 * N];

array<int, 4> Merge(array<int, 4> quad1, array<int, 4> quad2)
{
	map<int, int> mp;
	mp[quad1[0]] += quad1[2];
	mp[quad1[1]] += quad1[3];
	mp[quad2[0]] += quad2[2];
	mp[quad2[1]] += quad2[3];

	vector<pair<int, int>> vec;
	for (auto it : mp)
		vec.push_back(it);
	reverse(vec.begin(), vec.end());

	return {vec[0].first, vec[1].first, vec[0].second, vec[1].second};
}

void build(int idx, int lo, int hi)
{
	if (lo > hi)
		return;
	if (lo == hi)
	{
		seg[idx] = {arr[lo], -1, 1, 0};
		return;
	}

	int mid = (lo + hi) / 2;
	build(2 * idx + 1, lo, mid);
	build(2 * idx + 2, mid + 1, hi);

	seg[idx] = Merge(seg[2 * idx + 1], seg[2 * idx + 2]);
}

void point_update(int idx, int lo, int hi, int p, int x)
{
	if (lo > hi || p < lo || p > hi)
		return;
	if (lo == hi)
	{
		seg[idx] = {x, -1, 1, 0};
		return;
	}

	int mid = (lo + hi) / 2;
	if (p <= mid)
		point_update(2 * idx + 1, lo, mid, p, x);
	else
		point_update(2 * idx + 2, mid + 1, hi, p, x);

	seg[idx] = Merge(seg[2 * idx + 1], seg[2 * idx + 2]);
}

array<int, 4> range_query(int idx, int lo, int hi, int l, int r)
{
	if (lo > hi || r < lo || l > hi)
		return {-1, 0, -1, 0};

	if (lo >= l && hi <= r)
		return seg[idx];

	int mid = (lo + hi) / 2;

	return Merge(range_query(2 * idx + 1, lo, mid, l, r), range_query(2 * idx + 2, mid + 1, hi, l, r));
}

int main()
{
	FASTIO
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	build(0, 0, n - 1);

	while (q--)
	{
		int type, q1, q2;
		cin >> type >> q1 >> q2;
		if (type == 1)
			point_update(0, 0, n - 1, q1 - 1, q2);
		else
			cout << range_query(0, 0, n - 1, q1 - 1, q2 - 1)[3] << endl;
	}
}