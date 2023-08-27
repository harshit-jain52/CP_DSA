#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5;

ll arr[N];
ll seg[4 * N];
/*
0-based indexing: idx --> 2*idx+1 & 2*idx+2
1-based indexing: idx --> 2*idx & 2*idx+1
*/

/*
Query Types:
1. Range Sum
2. Point Updates
*/

void build(int idx, int lo, int hi) // O(N)
{
    if (lo > hi)
        return;
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

ll range_sum(int idx, int lo, int hi, int l, int r) // O(logN)
{
    if (r < lo || l > hi)
        return 0;

    if (lo >= l && hi <= r)
        return seg[idx];

    int mid = (lo + hi) / 2;

    return range_sum(2 * idx + 1, lo, mid, l, r) + range_sum(2 * idx + 2, mid + 1, hi, l, r);
}

void point_update(int idx, int lo, int hi, int i, ll val) // O(logN)
{
    // if (i < lo || i > hi)
    //     return;

    if (lo == hi)
    {
        seg[idx] += val;
        return;
    }

    int mid = (lo + hi) / 2;

    if (i <= mid)
        point_update(2 * idx + 1, lo, mid, i, val);
    else
        point_update(2 * idx + 2, mid + 1, hi, i, val);

    seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
}
