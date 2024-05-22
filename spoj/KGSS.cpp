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

struct node
{
	ll max1, max2;
	node() { max1 = max2 = -1; }
};

ll a[N];
node seg[4 * N];

node merge(node a, node b)
{
	node tmp;
	if (a.max1 > b.max1)
	{
		tmp.max1 = a.max1;
		tmp.max2 = max({b.max1, a.max2, b.max2});
	}
	else if (b.max1 > a.max1)
	{
		tmp.max1 = b.max1;
		tmp.max2 = max({a.max1, b.max2, a.max2});
	}
	else
	{
		tmp.max1 = tmp.max2 = a.max1;
	}
	return tmp;
}

void build(int id, int l, int r)
{
	if (l > r)
		return;
	if (l == r)
	{
		seg[id].max1 = a[l];
		seg[id].max2 = -1;
		return;
	}

	int mid = (l + r) / 2;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid + 1, r);
	seg[id] = merge(seg[id << 1], seg[id << 1 | 1]);
}

node query(int id, int l, int r, int lq, int rq)
{
	if (l > r || l > rq || lq > r)
		return node();
	if (l >= lq && r <= rq)
		return seg[id];

	int mid = (l + r) / 2;
	return merge(query(id << 1, l, mid, lq, rq), query(id << 1 | 1, mid + 1, r, lq, rq));
}

void update(int id, int l, int r, int pos, ll val)
{
	if (l > r || l > pos || pos > r)
		return;
	if (l == r)
	{
		seg[id].max1 = val;
		seg[id].max2 = -1;
		return;
	}

	int mid = (l + r) / 2;
	update(id << 1, l, mid, pos, val);
	update(id << 1 | 1, mid + 1, r, pos, val);
	seg[id] = merge(seg[id << 1], seg[id << 1 | 1]);
}

int main()
{
	FASTIO
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	build(1, 0, n - 1);

	int m;
	cin >> m;
	while (m--)
	{
		char type;
		cin >> type;
		if (type == 'Q')
		{
			int x, y;
			cin >> x >> y;
			node tmp = query(1, 0, n - 1, x - 1, y - 1);
			cout << tmp.max1 + tmp.max2 << endl;
		}
		else
		{
			int i, x;
			cin >> i >> x;
			update(1, 0, n - 1, i - 1, x);
		}
	}
}