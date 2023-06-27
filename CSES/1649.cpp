#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N = 2e5 + 10;
int arr[N], seg[4 * N];

void build(int idx, int lo, int hi)
{
    int mid = (lo + hi) / 2;

    if (lo == hi)
    {
        seg[idx] = arr[lo];
        return;
    }

    build(2 * idx + 1, lo, mid);
    build(2 * idx + 2, mid + 1, hi);

    seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
}

void update(int idx, int lo, int hi, int x, int val)
{
    if (lo > x || hi < x)
    {
        return;
    }

    if (lo == hi)
    {
        if (lo == x)
            seg[idx] = val;

        return;
    }
    int mid = (lo + hi) / 2;
    update(2 * idx + 1, lo, mid, x, val);
    update(2 * idx + 2, mid + 1, hi, x, val);

    seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
}

int query(int idx, int lo, int hi, int l, int r)
{
    if (lo >= l && hi <= r)
        return seg[idx];
    else if (hi < l || lo > r)
    {
        return INT_MAX;
    }
    else
    {
        int mid = (lo + hi) / 2;

        return min(query(2 * idx + 1, lo, mid, l, r), query(2 * idx + 2, mid + 1, hi, l, r));
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

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int k, u;
            cin >> k >> u;
            update(0, 0, n - 1, k - 1, u);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << query(0, 0, n - 1, l - 1, r - 1) << endl;
        }
    }
}