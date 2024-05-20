#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
#define F first
#define S second
typedef long long ll;
const int M = 1e9 + 7;
const int N = 2e5 + 5;

struct Edge
{
	int u;
	int v;
	ll wt;
};

vector<pair<int, ll>> g[N];
vector<int> euler;
vector<ll> arr;
ll seg[8 * N];
int ct1 = 0, ct2 = 0, in1[N], in2[N], out[N], depth[N];

void dfs(int v, int pp, int dd)
{
	in1[v] = ct1++;
	depth[v] = dd;
	euler.push_back(v);
	for (auto ch : g[v])
	{
		if (ch.F == pp)
			continue;

		arr.push_back(ch.S);
		in2[ch.F] = ct2++;
		dfs(ch.F, v, dd + 1);
		arr.push_back(-ch.S);
		out[ch.F] = ct2++;

		ct1++;
		euler.push_back(v);
	}
}

void build(int id, int l, int r)
{
	if (l > r)
		return;
	if (l == r)
	{
		seg[id] = arr[l];
		return;
	}

	int mid = (l + r) / 2;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid + 1, r);
	seg[id] = seg[id << 1] + seg[id << 1 | 1];
}

ll query(int id, int l, int r, int lq, int rq)
{
	if (l > r || l > rq || lq > r)
		return 0;
	if (l >= lq && r <= rq)
		return seg[id];

	int mid = (l + r) / 2;
	return query(id << 1, l, mid, lq, rq) + query(id << 1 | 1, mid + 1, r, lq, rq);
}

void update(int id, int l, int r, int pos, ll val)
{
	if (l > r || l > pos || pos > r)
		return;
	if (l == r)
	{
		seg[id] = val;
		return;
	}

	int mid = (l + r) / 2;
	update(id << 1, l, mid, pos, val);
	update(id << 1 | 1, mid + 1, r, pos, val);
	seg[id] = seg[id << 1] + seg[id << 1 | 1];
}

int main()
{
	FASTIO
	int n;
	cin >> n;
	Edge ed[n];
	for (int i = 1; i <= n - 1; i++)
	{
		cin >> ed[i].u >> ed[i].v >> ed[i].wt;
		g[ed[i].u].push_back({ed[i].v, ed[i].wt});
		g[ed[i].v].push_back({ed[i].u, ed[i].wt});
	}

	int root = 1;
	arr.push_back(0);
	in2[root] = ct2++;
	dfs(root, 0, 0);
	arr.push_back(0);
	out[root] = ct2++;

	// To Find LCA
	int sz = euler.size();
	int binLog[sz + 1];

	binLog[1] = 0;
	for (int i = 2; i <= sz; i++)
		binLog[i] = 1 + binLog[i / 2];

	pair<int, int> m[sz][binLog[sz] + 1];
	for (int i = 0; i < sz; i++)
		m[i][0] = {depth[euler[i]], euler[i]};

	for (int j = 1; j <= binLog[sz]; j++)
	{
		for (int i = 0; i + (1 << j) - 1 < sz; i++)
		{
			m[i][j] = min(m[i][j - 1], m[i + (1 << (j - 1))][j - 1]);
		}
	}

	// To Find Path Sum From Root to a Node
	build(1, 0, 2 * n - 1);

	int q;
	cin >> q;
	while (q--)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			int i;
			ll w;
			cin >> i >> w;
			int L = ed[i].u, R = ed[i].v;
			if (in2[L] > in2[R])
				swap(L, R);
			update(1, 0, 2 * n - 1, in2[R], w);
			update(1, 0, 2 * n - 1, out[R], -w);
		}
		else
		{
			int u, v;
			cin >> u >> v;
			int L = in1[u], R = in1[v];
			if (L > R)
				swap(L, R);

			int k = binLog[R - L + 1];
			auto pp = min(m[L][k], m[R - (1 << k) + 1][k]);
			int lca = pp.second;

			ll to_u = query(1, 0, 2 * n - 1, 0, in2[u]);
			ll to_v = query(1, 0, 2 * n - 1, 0, in2[v]);
			ll to_lca = query(1, 0, 2 * n - 1, 0, in2[lca]);

			cout << to_u + to_v - 2 * to_lca << endl;
		}
	}
}