#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;

ll arr[N];
ll tree[4 * N];
ll lazy[4 * N];

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

    tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
}

void range_update(int idx, int lo, int hi, int l, int r, ll val) // O(logN)
{
    int len = hi - lo + 1;

    if (lazy[idx] != 0)
    {
        tree[idx] += len * lazy[idx];

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
        tree[idx] += len * val;

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

    tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
}

ll range_query(int idx, int lo, int hi, int l, int r)
{
    if (lo > hi || lo > r || hi < l)
        return 0;

    int len = hi - lo + 1;

    if (lazy[idx] != 0)
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
    return range_query(2 * idx + 1, lo, mid, l, r) + range_query(2 * idx + 2, mid + 1, hi, l, r);
}

int main()
{
    FASTIO
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int b[m];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    build(0, 0, n - 1);

    for (int i = 0; i < m; i++)
    {
        ll balls = range_query(0, 0, n - 1, b[i], b[i]);
        range_update(0, 0, n - 1, b[i], b[i], -balls);

        ll upd = balls / n;
        range_update(0, 0, n - 1, 0, n - 1, upd);

        int left = balls % n;
        if (b[i] + left < n)
            range_update(0, 0, n - 1, b[i] + 1, b[i] + left, 1);
        else
        {
            range_update(0, 0, n - 1, b[i] + 1, n - 1, 1);
            range_update(0, 0, n - 1, 0, b[i] + left - n, 1);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << range_query(0, 0, n - 1, i, i) << " ";
    }
}