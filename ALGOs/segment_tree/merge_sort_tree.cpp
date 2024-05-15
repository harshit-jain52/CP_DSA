#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5;

// Query Type: ? l r x -> no of elements in range [l, r] <= x

ll arr[N];
vector<ll> seg[4 * N];

vector<ll> merge(vector<ll> &a, vector<ll> &b)
{
    int n = a.size(), m = b.size();
    int i = 0, j = 0;
    vector<ll> res;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            res.push_back(a[i]);
            i++;
        }
        else
        {
            res.push_back(b[j]);
            j++;
        }
    }

    while (i < n)
        res.push_back(a[i++]);
    while (j < m)
        res.push_back(b[j++]);

    return res;
}

void build(int id, int l, int r) // O(NlogN)
{
    if (l > r)
        return;
    if (l == r)
    {
        vector<ll> temp{arr[l]};
        seg[id] = temp;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * id + 1, l, mid);
    build(2 * id + 2, mid + 1, r);
    seg[id] = merge(seg[2 * id + 1], seg[2 * id + 2]);
}

int query(int id, int l, int r, int lq, int rq, int x)
{
    if (lq > r || rq < l)
        return 0;

    if (lq <= l && rq >= r)
        return (upper_bound(seg[id].begin(), seg[id].end(), x) - seg[id].begin());

    int mid = (l + r) / 2;
    return (query(2 * id + 1, l, mid, lq, rq, x) + query(2 * id + 2, mid + 1, r, lq, rq, x));
}