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
        int l, r;
        cin >> l >> r;
        l = l - 1, r = r - 1; // 0-based indexing
        cout << query(0, 0, n - 1, l, r) << endl;
    }
}