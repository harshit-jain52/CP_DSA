#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int N = 2e5 + 5;

struct node
{
    ll sum;
    ll lazyinc;
    ll lazyset;

    node()
    {
        sum = 0;
        lazyinc = 0;
        lazyset = 0;
    }
};

node seg[4 * N];
ll t[N];

node merge(node a, node b)
{
    node temp;
    temp.sum = a.sum + b.sum;
    return temp;
}

void push(int id, int l, int r)
{
    if (seg[id].lazyset)
    {
        seg[id].sum = seg[id].lazyset * (r - l + 1);
        if (l != r)
        {
            seg[2 * id + 1].lazyset = seg[id].lazyset;
            seg[2 * id + 2].lazyset = seg[id].lazyset;
            seg[2 * id + 1].lazyinc = 0;
            seg[2 * id + 2].lazyinc = 0;
        }
        seg[id].lazyset = 0;
    }
    if (seg[id].lazyinc)
    {
        seg[id].sum += seg[id].lazyinc * (r - l + 1);
        if (l != r)
        {
            seg[2 * id + 1].lazyinc += seg[id].lazyinc;
            seg[2 * id + 2].lazyinc += seg[id].lazyinc;
        }
        seg[id].lazyinc = 0;
    }
}

void build(int id, int l, int r)
{
    if (l > r)
        return;
    if (l == r)
    {
        seg[id].sum = t[l];
        return;
    }

    int mid = (l + r) / 2;
    build(2 * id + 1, l, mid);
    build(2 * id + 2, mid + 1, r);

    seg[id] = merge(seg[2 * id + 1], seg[2 * id + 2]);
}

void update(int id, int l, int r, int lq, int rq, int x, bool type)
{
    push(id, l, r);
    if (lq > r || rq < l)
        return;
    if (lq <= l && rq >= r)
    {
        if (type)
            seg[id].lazyinc = x;
        else
            seg[id].lazyset = x;
        push(id, l, r);
        return;
    }

    int mid = (l + r) / 2;
    update(2 * id + 1, l, mid, lq, rq, x, type);
    update(2 * id + 2, mid + 1, r, lq, rq, x, type);
    seg[id] = merge(seg[2 * id + 1], seg[2 * id + 2]);
}

node query(int id, int l, int r, int lq, int rq)
{
    push(id, l, r);
    if (lq > r || rq < l)
        return node();
    if (lq <= l && rq >= r)
        return seg[id];
    int mid = (l + r) / 2;
    return merge(query(2 * id + 1, l, mid, lq, rq), query(2 * id + 2, mid + 1, r, lq, rq));
}

int main()
{
    FASTIO
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> t[i];

    build(0, 0, n - 1);
    while (q--)
    {
        int type, a, b;
        cin >> type >> a >> b;
        if (type == 3)
            cout << query(0, 0, n - 1, a - 1, b - 1).sum << endl;
        else
        {
            ll x;
            cin >> x;
            update(0, 0, n - 1, a - 1, b - 1, x, (type == 1));
        }
    }
}