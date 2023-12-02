#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;
const int N = 2e5 + 10;

ll seg[4 * N];

ll maxInRange(int idx, int lo, int hi, int l, int r)
{
    if (lo >= l && hi <= r)
        return seg[idx];

    if (hi < l || lo > r)
        return 0;

    int mid = (lo + hi) / 2;
    return max(maxInRange(2 * idx + 1, lo, mid, l, r), maxInRange(2 * idx + 2, mid + 1, hi, l, r));
}

void point_update(int idx, int lo, int hi, int i, ll val)
{
    if (lo == hi)
    {
        seg[idx] = val;
        return;
    }

    int mid = (lo + hi) / 2;

    if (i <= mid)
        point_update(2 * idx + 1, lo, mid, i, val);
    else
        point_update(2 * idx + 2, mid + 1, hi, i, val);

    seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int h[n];
    ll a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
        h[i]--; // 0-based
    }

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        ll maxdp = maxInRange(0, 0, n - 1, 0, h[i] - 1);
        point_update(0, 0, n - 1, h[i], maxdp + a[i]);
    }

    cout << maxInRange(0, 0, n - 1, 0, n - 1);
}