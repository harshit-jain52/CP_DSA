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
    ll lazyct;
    ll lazysum;
    ll tot;
    node() { lazyct = lazysum = tot = 0; }
};

int arr[N];
node seg[4 * N];

node merge(node a, node b)
{
    node tmp;
    tmp.tot = a.tot + b.tot;
    return tmp;
}

void build(int id, int l, int r)
{
    if (l > r)
        return;
    if (l == r)
    {
        seg[id].tot = arr[l];
        return;
    }

    int mid = (l + r) / 2;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    seg[id] = merge(seg[id << 1], seg[id << 1 | 1]);
}

void push(int id, int l, int r)
{
    if (seg[id].lazyct)
    {
        seg[id].tot += seg[id].lazysum * (r - l + 1) + seg[id].lazyct * (r + l) * (r - l + 1) / 2;
        if (l != r)
        {
            seg[id << 1].lazyct += seg[id].lazyct;
            seg[id << 1 | 1].lazyct += seg[id].lazyct;
            seg[id << 1].lazysum += seg[id].lazysum;
            seg[id << 1 | 1].lazysum += seg[id].lazysum;
        }
        seg[id].lazyct = seg[id].lazysum = 0;
    }
}

void update(int id, int l, int r, int lq, int rq)
{
    push(id, l, r);
    if (l > rq || lq > r)
        return;
    if (lq <= l && rq >= r)
    {
        seg[id].lazyct++;
        seg[id].lazysum += (1 - lq);
        push(id, l, r);
        return;
    }

    int mid = (l + r) / 2;
    update(id << 1, l, mid, lq, rq);
    update(id << 1 | 1, mid + 1, r, lq, rq);
    seg[id] = merge(seg[id << 1], seg[id << 1 | 1]);
}

node query(int id, int l, int r, int lq, int rq)
{
    push(id, l, r);
    if (l > rq || lq > r)
        return node();
    if (lq <= l && rq >= r)
        return seg[id];

    int mid = (l + r) / 2;
    return merge(query(id << 1, l, mid, lq, rq), query(id << 1 | 1, mid + 1, r, lq, rq));
}

int main()
{
    FASTIO
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    build(1, 0, n - 1);

    while (q--)
    {
        int type, a, b;
        cin >> type >> a >> b;
        if (type == 1)
            update(1, 0, n - 1, a - 1, b - 1);
        else
            cout << query(1, 0, n - 1, a - 1, b - 1).tot << endl;
    }
}