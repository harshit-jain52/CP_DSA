#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int N = 1e6 + 10;

int seg[4 * N];

int maxInRange(int idx, int lo, int hi, int l, int r)
{
    if (lo >= l && hi <= r)
        return seg[idx];

    if (hi < l || lo > r)
        return 0;

    int mid = (lo + hi) / 2;
    return max(maxInRange(2 * idx + 1, lo, mid, l, r), maxInRange(2 * idx + 2, mid + 1, hi, l, r));
}

void point_update(int idx, int lo, int hi, int i, int val)
{
    if (lo == hi)
    {
        seg[idx] = max(seg[idx], val);
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
    FASTIO
    int n, d;
    cin >> n >> d;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        int dp = maxInRange(0, 0, N - 1, max(0, a[i] - d), a[i] + d);
        point_update(0, 0, N - 1, a[i], 1 + dp);
    }

    cout << maxInRange(0, 0, N - 1, 0, N - 1);
}