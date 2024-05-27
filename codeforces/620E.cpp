#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int N = 4e5 + 1;

struct node
{
    ll color, lazy;
    node() { color = lazy = 0; }
};

vector<int> g[N];
int in[N], out[N];
int timer = 0;

void dfs(int v, int p)
{
    in[v] = timer++;

    for (int ch : g[v])
    {
        if (ch != p)
            dfs(ch, v);
    }

    out[v] = timer;
}

ll init[N];
node seg[4 * N];

node merge(node a, node b)
{
    node tmp;
    tmp.color = a.color | b.color;
    return tmp;
}

void build(int id, int l, int r)
{
    if (l > r)
        return;
    if (l == r)
    {
        seg[id].color = init[l];
        return;
    }

    int mid = (l + r) / 2;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    seg[id] = merge(seg[id << 1], seg[id << 1 | 1]);
}

void push(int id, int l, int r)
{
    if (seg[id].lazy)
    {
        seg[id].color = seg[id].lazy;
        if (l != r)
        {
            seg[id << 1].lazy = seg[id].lazy;
            seg[id << 1 | 1].lazy = seg[id].lazy;
        }
        seg[id].lazy = 0;
    }
}

void update(int id, int l, int r, int lq, int rq, int c)
{
    push(id, l, r);

    if (l > rq || lq > r)
        return;
    if (l >= lq && r <= rq)
    {
        seg[id].lazy = (1LL << c);
        push(id, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update(id << 1, l, mid, lq, rq, c);
    update(id << 1 | 1, mid + 1, r, lq, rq, c);
    seg[id] = merge(seg[id << 1], seg[id << 1 | 1]);
}

node query(int id, int l, int r, int lq, int rq)
{
    push(id, l, r);
    if (l > rq || lq > r)
        return node();
    if (l >= lq && r <= rq)
        return seg[id];
    int mid = (l + r) / 2;
    return merge(query(id << 1, l, mid, lq, rq), query(id << 1 | 1, mid + 1, r, lq, rq));
}

int main()
{
    FASTIO
    int n, m;
    cin >> n >> m;

    int col[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> col[i];

    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++)
        init[in[i]] = (1LL << col[i]);
    build(1, 0, n - 1);

    while (m--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int v, c;
            cin >> v >> c;
            update(1, 0, n - 1, in[v], out[v] - 1, c);
        }
        else
        {
            int v;
            cin >> v;
            ll res = query(1, 0, n - 1, in[v], out[v] - 1).color;
            cout << __builtin_popcountll(res) << endl;
        }
    }
}