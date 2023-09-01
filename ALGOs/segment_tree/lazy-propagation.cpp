#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5;

ll arr[N];
ll tree[4 * N];
ll lazy[4 * N];
/*
0-based indexing: idx --> 2*idx+1 & 2*idx+2
1-based indexing: idx --> 2*idx & 2*idx+1
*/

/*
Query Types:
1. Range Sum
2. Range Updates
*/

void build(int idx, int lo, int hi) // O(N)
{
    lazy[idx] = 0;

    if (lo == hi)
    {
        tree[idx] = arr[lo];
    }

    int mid = (lo + hi) / 2;

    build(2 * idx + 1, lo, mid);
    build(2 * idx + 2, mid + 1, hi);

    tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
}

void range_update(int idx, int lo, int hi, int l, int r, ll val) // O(logN)
{
    int len = hi - lo + 1;

    if (lazy[idx] != 0) // resolve pending updates
    {
        tree[idx] += len * lazy[idx];

        if (lo != hi)
        {
            lazy[2 * idx + 1] += lazy[idx];
            lazy[2 * idx + 2] += lazy[idx];
        }

        lazy[idx] = 0;
    }

    if (lo > hi || lo > r || hi < l) // out of range
        return;

    if (lo >= l && hi <= r) // complete overlap
    {
        tree[idx] += len * val;

        if (lo != hi)
        {
            lazy[2 * idx + 1] += val;
            lazy[2 * idx + 2] += val;
        }

        return;
    }

    // partial overlap

    int mid = (lo + hi) / 2;
    range_update(2 * idx + 1, lo, mid, l, r, val);
    range_update(2 * idx + 2, mid + 1, hi, l, r, val);

    tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
}

ll range_query(int idx, int lo, int hi, int l, int r) // O(logN)
{
    if (lo > hi || lo > r || hi < l)
        return 0;

    int len = hi - lo + 1;

    if (lazy[idx] != 0) // resolve pending updates
    {
        tree[idx] += len * lazy[idx];

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
    return range_query(2 * idx + 1, lo, mid, l, r) + range_query(2 * idx + 1, mid + 1, hi, l, r);
}