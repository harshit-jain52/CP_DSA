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
    ll mx, sum;
    node() { mx = sum = 0; }
};

ll arr[N];
node seg[4 * N];

node merge(node a, node b)
{
    node tmp;
    tmp.sum = a.sum + b.sum;
    tmp.mx = max(a.mx, b.mx);
    return tmp;
}

void build(int id, int l, int r)
{
    if (l > r)
        return;
    if (l == r)
    {
        seg[id].sum = seg[id].mx = arr[l];
        return;
    }

    int mid = (l + r) / 2;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    seg[id] = merge(seg[id << 1], seg[id << 1 | 1]);
}

void modulo(int id, int l, int r, int lq, int rq, int x)
{
    if (l > r || lq > r || l > rq || seg[id].mx < x)
        return;
    if (l == r)
    {
        arr[l] %= x;
        seg[id].mx = seg[id].sum = arr[l];
        return;
    }

    int mid = (l + r) / 2;
    modulo(id << 1, l, mid, lq, rq, x);
    modulo(id << 1 | 1, mid + 1, r, lq, rq, x);
    seg[id] = merge(seg[id << 1], seg[id << 1 | 1]);
}

void update(int id, int l, int r, int pos, int x)
{
    if (l > r || l > pos || pos > r)
        return;
    if (l == r)
    {
        arr[l] = x;
        seg[id].mx = seg[id].sum = arr[l];
        return;
    }

    int mid = (l + r) / 2;
    update(id << 1, l, mid, pos, x);
    update(id << 1 | 1, mid + 1, r, pos, x);
    seg[id] = merge(seg[id << 1], seg[id << 1 | 1]);
}

node query(int id, int l, int r, int lq, int rq)
{
    if (l > r || lq > r || l > rq)
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
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    build(1, 0, n - 1);

    while (m--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            cout << query(1, 0, n - 1, l - 1, r - 1).sum << endl;
        }
        else if (type == 2)
        {
            int l, r, x;
            cin >> l >> r >> x;
            modulo(1, 0, n - 1, l - 1, r - 1, x);
        }
        else
        {
            int k, x;
            cin >> k >> x;
            update(1, 0, n - 1, k - 1, x);
        }
    }
}