#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N = 2e5 + 5;
ll arr[N], seg[4 * N], lazy1[4 * N], lazy2[4 * N];

void build(int idx, int lo, int hi)
{
    lazy1[idx] = lazy2[idx] = 0;
    if (lo == hi)
    {
        seg[idx] = arr[lo];
        return;
    }

    int mid = (lo + hi) / 2;
    build(2 * idx + 1, lo, mid);
    build(2 * idx + 2, mid + 1, hi);

    seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
}

void query1(int idx, int lo, int hi, int l, int r, ll x)
{
    if (lazy2[idx] != 0)
    {
        seg[idx] = (hi - lo + 1) * lazy2[idx];
        if (lo != hi)
        {
            lazy2[2 * idx + 1] = lazy2[idx];
            lazy2[2 * idx + 2] = lazy2[idx];
        }
        lazy2[idx] = 0;
    }

    if (lazy1[idx] != 0)
    {
        seg[idx] += (hi - lo + 1) * lazy1[idx];
        if (lo != hi)
        {
            lazy1[2 * idx + 1] += lazy1[idx];
            lazy1[2 * idx + 2] += lazy1[idx];
        }
        lazy1[idx] = 0;
    }

    if (lo > r || hi < l)
        return;

    if (lo >= l && hi <= r)
    {
        seg[idx] += (hi - lo + 1) * x;
        if (lo != hi)
        {
            lazy1[2 * idx + 1] += x;
            lazy1[2 * idx + 2] += x;
        }
        return;
    }

    int mid = (lo + hi) / 2;
    query1(2 * idx + 1, lo, mid, l, r, x);
    query1(2 * idx + 2, mid + 1, hi, l, r, x);
    seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
}

void query2(int idx, int lo, int hi, int l, int r, ll x)
{
    if (lazy2[idx] != 0)
    {
        seg[idx] = (hi - lo + 1) * lazy2[idx];
        if (lo != hi)
        {
            lazy2[2 * idx + 1] = lazy2[idx];
            lazy2[2 * idx + 2] = lazy2[idx];
        }
        lazy2[idx] = 0;
    }

    if (lazy1[idx] != 0)
    {
        seg[idx] += (hi - lo + 1) * lazy1[idx];
        if (lo != hi)
        {
            lazy1[2 * idx + 1] += lazy1[idx];
            lazy1[2 * idx + 2] += lazy1[idx];
        }
        lazy1[idx] = 0;
    }

    if (lo > r || hi < l)
        return;

    if (lo >= l && hi <= r)
    {
        seg[idx] = (hi - lo + 1) * x;
        if (lo != hi)
        {
            lazy2[2 * idx + 1] = x;
            lazy2[2 * idx + 2] = x;
            lazy1[2 * idx + 1] = 0;
            lazy1[2 * idx + 1] = 0;
        }
        return;
    }

    int mid = (lo + hi) / 2;
    query2(2 * idx + 1, lo, mid, l, r, x);
    query2(2 * idx + 2, mid + 1, hi, l, r, x);
    seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
}

ll query3(int idx, int lo, int hi, int l, int r)
{
    if (lazy2[idx] != 0)
    {
        seg[idx] = (hi - lo + 1) * lazy2[idx];
        if (lo != hi)
        {
            lazy2[2 * idx + 1] = lazy2[idx];
            lazy2[2 * idx + 2] = lazy2[idx];
        }
        lazy2[idx] = 0;
    }

    if (lazy1[idx] != 0)
    {
        seg[idx] += (hi - lo + 1) * lazy1[idx];
        if (lo != hi)
        {
            lazy1[2 * idx + 1] += lazy1[idx];
            lazy1[2 * idx + 2] += lazy1[idx];
        }
        lazy1[idx] = 0;
    }

    if (lo > r || hi < l)
        return 0;

    if (lo >= l && hi <= r)
    {
        return seg[idx];
    }
    else
    {
        int mid = (lo + hi) / 2;
        ll left = query3(2 * idx + 1, lo, mid, l, r);
        ll right = query3(2 * idx + 2, mid + 1, hi, l, r);
        return (left + right);
    }
}

int main()
{
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    build(0, 0, n - 1);

    // for (int i = 0; i < 4 * n; i++)
    // {
    //     cout << seg[i] << " ";
    // }

    while (q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int a, b;
            ll x;
            cin >> a >> b >> x;
            query1(0, 0, n - 1, a - 1, b - 1, x);
        }
        else if (type == 2)
        {
            int a, b;
            ll x;
            cin >> a >> b >> x;
            query2(0, 0, n - 1, a - 1, b - 1, x);
        }
        else
        {
            int a, b;
            cin >> a >> b;
            cout << query3(0, 0, n - 1, a - 1, b - 1) << endl;
        }
    }
}