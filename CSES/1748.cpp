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
int seg[4 * N];

int sumInRange(int idx, int lo, int hi, int l, int r)
{
	if (lo >= l && hi <= r)
		return seg[idx];

	if (hi < l || lo > r)
		return 0;

	int mid = (lo + hi) / 2;
	return (sumInRange(2 * idx + 1, lo, mid, l, r) + sumInRange(2 * idx + 2, mid + 1, hi, l, r)) % M;
}

void point_update(int idx, int lo, int hi, int i, int val)
{
	if (lo == hi)
	{
		seg[idx] = (seg[idx] + val) % M;
		return;
	}

	int mid = (lo + hi) / 2;

	if (i <= mid)
		point_update(2 * idx + 1, lo, mid, i, val);
	else
		point_update(2 * idx + 2, mid + 1, hi, i, val);

	seg[idx] = (seg[2 * idx + 1] + seg[2 * idx + 2]) % M;
}

int main()
{
	FASTIO
	int n;
	cin >> n;
	int x[n];
	set<int> st;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
		st.insert(x[i]);
	}

	int ct = 0;
	map<int, int> mp;
	for (auto it : st)
		mp[it] = ct++;

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int tmp = (sumInRange(0, 0, ct - 1, 0, mp[x[i]] - 1) + 1) % M;
		ans = (ans + tmp) % M;
		point_update(0, 0, ct - 1, mp[x[i]], tmp);
	}

	cout << ans;
}