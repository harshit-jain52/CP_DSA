#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N = 2e5 + 10;

ll arr[N], lazy[4 * N];

void build(int idx, int lo, int hi)
{
    lazy[idx] = 0;
    if (lo == hi)
    {
        return;
    }

    int mid = (lo + hi) / 2;
    build(2 * idx + 1, lo, mid);
    build(2 * idx + 2, mid + 1, hi);
}

void update(int idx, int lo, int hi, int l, int r, ll val)
{

    if (lazy[idx] != 0 && lo != hi)
    {
        lazy[2 * idx + 1] += lazy[idx];
        lazy[2 * idx + 2] += lazy[idx];
        lazy[idx] = 0;
    }

    if (lo > r || hi < l)
        return;

    if (lo >= l && hi <= r)
    {
        lazy[idx] += val;
    }
    else
    {
        int mid = (lo + hi) / 2;
        update(2 * idx + 1, lo, mid, l, r, val);
        update(2 * idx + 2, mid + 1, hi, l, r, val);
    }
}

void query(int idx, int lo, int hi, int i)
{
    if (lo > i || hi < i)
    {
        return;
    }

    if (lo == hi)
    {
        arr[lo] += lazy[idx];
        lazy[idx] = 0;
        return;
    }

    if (lazy[idx] != 0)
    {
        lazy[2 * idx + 1] += lazy[idx];
        lazy[2 * idx + 2] += lazy[idx];
        lazy[idx] = 0;
    }
    int mid = (lo + hi) / 2;
    query(2 * idx + 1, lo, mid, i);
    query(2 * idx + 2, mid + 1, hi, i);
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
            int a, b;
            ll u;
            cin >> a >> b >> u;
            update(0, 0, n - 1, a - 1, b - 1, u);
        }
        else
        {
            int k;
            cin >> k;
            query(0, 0, n - 1, k - 1);
            cout << arr[k - 1] << endl;
        }
    }
}