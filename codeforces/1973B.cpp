#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int N = 1e5 + 5;

int arr[N], seg[4 * N];
int n;

void build(int idx, int lo, int hi)
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

    seg[idx] = seg[2 * idx + 1] | seg[2 * idx + 2];
}

int range(int idx, int lo, int hi, int l, int r)
{
    if (r < lo || l > hi)
        return 0;

    if (lo >= l && hi <= r)
        return seg[idx];

    int mid = (lo + hi) / 2;

    return range(2 * idx + 1, lo, mid, l, r) | range(2 * idx + 2, mid + 1, hi, l, r);
}

bool check(int k)
{
    int val = range(0, 0, n - 1, 0, k - 1);
    for (int i = 1; i + k - 1 < n; i++)
    {
        int tmp = range(0, 0, n - 1, i, i + k - 1);
        if (tmp != val)
            return false;
    }
    return true;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    build(0, 0, n - 1);
    int ans = n;
    int lo = 1, hi = n, mid;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (check(mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    cout << ans << endl;
}

int main()
{
    FASTIO
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}