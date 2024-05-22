#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int N = 1e6 + 1;
const int SZ = 1e5 + 5;

int sp[N];
void leastPrimeFactor()
{
    for (int i = 1; i < N; i++)
        sp[i] = i;

    for (int i = 2; i < N; i++)
    {
        if (sp[i] == i)
        {
            for (int j = 2 * i; j < N; j += i)
                sp[j] = min(sp[j], i);
        }
    }
}

struct node
{
    int mx;
    bool done;
    node()
    {
        mx = 0;
        done = false;
    }
};

int arr[SZ];
node seg[4 * SZ];

node merge(node a, node b)
{
    node tmp;
    tmp.mx = max(a.mx, b.mx);
    tmp.done = a.done && b.done;
    return tmp;
}

void build(int id, int l, int r)
{
    if (l > r)
        return;
    if (l == r)
    {
        seg[id].mx = sp[arr[l]];
        seg[id].done = arr[l] == 1;
        return;
    }

    int mid = (l + r) / 2;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
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

void update(int id, int l, int r, int lq, int rq)
{
    if (l > r || lq > r || l > rq || seg[id].done)
        return;
    if (l == r)
    {
        arr[l] = arr[l] / sp[arr[l]];
        seg[id].mx = sp[arr[l]];
        seg[id].done = arr[l] == 1;
        return;
    }

    int mid = (l + r) / 2;
    update(id << 1, l, mid, lq, rq);
    update(id << 1 | 1, mid + 1, r, lq, rq);
    seg[id] = merge(seg[id << 1], seg[id << 1 | 1]);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    build(1, 0, n - 1);
    while (m--)
    {
        int type, l, r;
        cin >> type >> l >> r;
        if (type)
            cout << query(1, 0, n - 1, l - 1, r - 1).mx << " ";
        else
            update(1, 0, n - 1, l - 1, r - 1);
    }
    cout << endl;
}

int main()
{
    FASTIO
    leastPrimeFactor();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}