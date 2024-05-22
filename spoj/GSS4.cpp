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
	ll sum;
	bool done;
	node()
	{
		sum = 0;
		done = false;
	}
};

ll a[N];
node seg[4 * N];

node merge(node a, node b)
{
	node tmp;
	tmp.sum = a.sum + b.sum;
	tmp.done = a.done && b.done;
	return tmp;
}

void build(int id, int l, int r)
{
	if (l > r)
		return;
	if (l == r)
	{
		seg[id].sum = a[l];
		seg[id].done = a[l] == 1;
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

void update(int id, int l, int r, int lq, int rq)
{
	if (l > r || l > rq || lq > r || seg[id].done)
		return;
	if (l == r)
	{
		seg[id].sum = sqrt(seg[id].sum);
		seg[id].done = seg[id].sum == 1;
		return;
	}

	int mid = (l + r) / 2;
	update(id << 1, l, mid, lq, rq);
	update(id << 1 | 1, mid + 1, r, lq, rq);
	seg[id] = merge(seg[id << 1], seg[id << 1 | 1]);
}

int main()
{
	FASTIO
	int t = 1, n;
	while (cin >> n)
	{
		cout << "Case #" << t << ":\n";
		for (int i = 0; i < n; i++)
			cin >> a[i];

		build(1, 0, n - 1);
		int m;
		cin >> m;
		while (m--)
		{
			int type, x, y;
			cin >> type >> x >> y;
			if (x > y)
				swap(x, y);

			if (type)
				cout << query(1, 0, n - 1, x - 1, y - 1).sum << endl;
			else
				update(1, 0, n - 1, x - 1, y - 1);
		}
		t++;
		cout << endl;
	}
}