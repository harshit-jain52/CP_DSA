#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;
const int N = 2e5 + 10;

ll arr[N], tree[4 * N], lazy[4 * N];

void build(int idx, int lo, int hi)
{
    lazy[idx] = 0;

    if (lo == hi)
    {
        tree[idx] = arr[lo];
        return;
    }

    int mid = (lo + hi) / 2;

    build(2 * idx + 1, lo, mid);
    build(2 * idx + 2, mid + 1, hi);

    tree[idx] = min(tree[2 * idx + 1], tree[2 * idx + 2]);
}

void range_update(int idx, int lo, int hi, int l, int r, ll val)
{
    if (lazy[idx] != 0)
    {
        tree[idx] += lazy[idx];

        if (lo != hi)
        {
            lazy[2 * idx + 1] += lazy[idx];
            lazy[2 * idx + 2] += lazy[idx];
        }

        lazy[idx] = 0;
    }

    if (lo > hi || lo > r || hi < l)
        return;

    if (lo >= l && hi <= r)
    {
        tree[idx] += val;

        if (lo != hi)
        {
            lazy[2 * idx + 1] += val;
            lazy[2 * idx + 2] += val;
        }

        return;
    }

    int mid = (lo + hi) / 2;
    range_update(2 * idx + 1, lo, mid, l, r, val);
    range_update(2 * idx + 2, mid + 1, hi, l, r, val);

    tree[idx] = min(tree[2 * idx + 1], tree[2 * idx + 2]);
}

ll range_query(int idx, int lo, int hi, int l, int r)
{
    if (lo > hi || lo > r || hi < l)
        return LONG_LONG_MAX;

    if (lazy[idx] != 0)
    {
        tree[idx] += lazy[idx];

        if (lo != hi)
        {
            lazy[2 * idx + 1] += lazy[idx];
            lazy[2 * idx + 2] += lazy[idx];
        }

        lazy[idx] = 0;
    }

    if (lo >= l && hi <= r)
        return tree[idx];

    int mid = (lo + hi) / 2;
    return min(range_query(2 * idx + 1, lo, mid, l, r), range_query(2 * idx + 2, mid + 1, hi, l, r));
}

int main()
{
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    build(0, 0, n - 1);

    cin >> m;
    cin.ignore();

    while (m--)
    {
        string str;
        getline(cin, str);

        int arr[3];
        int idx = 0;

        stringstream ss(str);
        string token;
        while (ss >> token)
        {
            arr[idx++] = stoi(token);
        }

        if (idx == 2)
        {
            int lf = arr[0], rg = arr[1];

            if (rg < lf)
                cout << min(range_query(0, 0, n - 1, 0, rg), range_query(0, 0, n - 1, lf, n - 1)) << endl;
            else
                cout << range_query(0, 0, n - 1, lf, rg) << endl;
        }

        if (idx == 3)
        {
            int lf = arr[0], rg = arr[1];
            ll v = arr[2];

            if (rg < lf)
            {
                range_update(0, 0, n - 1, 0, rg, v);
                range_update(0, 0, n - 1, lf, n - 1, v);
            }
            else
                range_update(0, 0, n - 1, lf, rg, v);
        }
    }
}