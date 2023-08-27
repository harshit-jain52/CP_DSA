#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5;

ll arr[N];
ll seg[4 * N];
ll tag[4 * N];
/*
0-based indexing: idx --> 2*idx+1 & 2*idx+2
1-based indexing: idx --> 2*idx & 2*idx+1
*/

/*
Query Types:
1. Point Value
2. Range Updates
*/

void build(int idx, int lo, int hi) // O(N)
{
    if (lo > hi)
        return;

    tag[idx] = 0;

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

void range_update(int idx, int lo, int hi, int l, int r, ll val) // O(logN)
{
    if (r < lo || l > hi)
        return;

    if (lo >= l && hi <= r)
    {
        tag[idx] += val;
        return;
    }

    int mid = (lo + hi) / 2;

    range_update(2 * idx + 1, lo, mid, l, r, val);
    range_update(2 * idx + 2, mid + 1, hi, l, r, val);
}

ll point_value(int idx, int lo, int hi, int i)
{
    if (lo == hi)
    {
        return tag[idx] + seg[idx];
    }

    int mid = (lo + hi) / 2;

    if (i <= mid)
        return tag[idx] + point_value(2 * idx + 1, lo, mid, i);
    else
        return tag[idx] + point_value(2 * idx + 2, mid + 1, hi, i);
}
