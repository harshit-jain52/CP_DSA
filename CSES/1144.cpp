#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int N = 6e5 + 10;

int arr[N];
int seg[4 * N];

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

int range_sum(int idx, int lo, int hi, int l, int r)
{
	if (r < lo || l > hi)
		return 0;

	if (lo >= l && hi <= r)
		return seg[idx];

	int mid = (lo + hi) / 2;

	return range_sum(2 * idx + 1, lo, mid, l, r) + range_sum(2 * idx + 2, mid + 1, hi, l, r);
}

void point_update(int idx, int lo, int hi, int i, int val)
{
	if (lo == hi)
	{
		seg[idx] += val;
		return;
	}

	int mid = (lo + hi) / 2;

	if (i <= mid)
		point_update(2 * idx + 1, lo, mid, i, val);
	else
		point_update(2 * idx + 2, mid + 1, hi, i, val);

	seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
}

int main()
{
	FASTIO
	int n, q;
	cin >> n >> q;
	int p[n + 1];

	vector<int> vec;
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
		vec.push_back(p[i]);
	}

	vector<pair<char, pair<int, int>>> queries;
	while (q--)
	{
		char c;
		int a, b;
		cin >> c >> a >> b;
		if (c == '!')
			vec.push_back(b);
		else
		{
			vec.push_back(a);
			vec.push_back(b);
		}
		queries.push_back({c, {a, b}});
	}

	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	int idx = 0;
	unordered_map<int, int> cc; // coordinate compression
	for (int it : vec)
	{
		cc[it] = idx++;
	}
	int sz = idx;
	for (int i = 1; i <= n; i++)
	{
		arr[cc[p[i]]]++;
	}

	build(0, 0, sz - 1);
	for (auto query : queries)
	{
		if (query.first == '!')
		{
			int emp = query.second.first;
			int newSal = query.second.second;

			point_update(0, 0, sz - 1, cc[p[emp]], -1);
			p[emp] = newSal;
			point_update(0, 0, sz - 1, cc[p[emp]], 1);
		}
		else
		{
			int a = query.second.first, b = query.second.second;
			cout << range_sum(0, 0, sz - 1, cc[a], cc[b]) << endl;
		}
	}
}