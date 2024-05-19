#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 1;

struct node
{
    int id;
    int ct;
    node() { id = -1, ct = 0; }
};

ll sk[N];
node seg[4 * N];

node merge(node a, node b)
{
    node temp;
    if (a.id == -1)
        temp.id = b.id;
    else if (b.id == -1)
        temp.id = a.id;
    else
    {
        if (sk[a.id] > sk[b.id])
            temp.id = a.id;
        else if (sk[b.id] > sk[a.id])
            temp.id = b.id;
        else
            temp.id = min(a.id, b.id);
    }
    temp.ct = a.ct + b.ct;
    return temp;
}

void build(int idx, int l, int r)
{
    if (l > r)
        return;
    if (l == r)
    {
        seg[idx].ct = 1;
        seg[idx].id = l;
        return;
    }

    int mid = (l + r) / 2;
    build(idx << 1, l, mid);
    build(idx << 1 | 1, mid + 1, r);
    seg[idx] = merge(seg[idx << 1], seg[idx << 1 | 1]);
}

node searchFirstM(int idx, int l, int r, int m)
{
    if (l > r || m <= 0)
        return node();
    if (seg[idx].ct <= m)
        return seg[idx];

    int mid = (l + r) / 2;
    return merge(searchFirstM(idx << 1, l, mid, m), searchFirstM(idx << 1 | 1, mid + 1, r, m - seg[idx << 1].ct));
}

node searchLastM(int idx, int l, int r, int m)
{
    if (l > r || m <= 0)
        return node();
    if (seg[idx].ct <= m)
        return seg[idx];

    int mid = (l + r) / 2;
    return merge(searchLastM(idx << 1, l, mid, m - seg[idx << 1 | 1].ct), searchLastM(idx << 1 | 1, mid + 1, r, m));
}

void remove(int idx, int l, int r, int pos)
{
    if (l > r || pos < l || pos > r)
        return;
    if (l == r)
    {
        seg[idx].ct = 0;
        seg[idx].id = -1;
        return;
    }

    int mid = (l + r) / 2;
    remove(idx << 1, l, mid, pos);
    remove(idx << 1 | 1, mid + 1, r, pos);

    seg[idx] = merge(seg[idx << 1], seg[idx << 1 | 1]);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> sk[i];
    build(1, 0, n - 1);

    for (int i = 0; i < m; i++)
    {
        node best = merge(searchFirstM(1, 0, n - 1, m), searchLastM(1, 0, n - 1, m));
        cout << best.id + 1 << " ";
        remove(1, 0, n - 1, best.id);
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}