#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int arr[N];
int seg[4 * N];
int whole = ((1LL << 31) - 1);

void reset(int idx, int lo, int hi)
{
    if (lo > hi)
        return;
    if (lo == hi)
    {
        seg[idx] = whole;
        return;
    }

    int mid = (lo + hi) / 2;

    reset(2 * idx + 1, lo, mid);
    reset(2 * idx + 2, mid + 1, hi);

    seg[idx] = whole;
}

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

    seg[idx] = (seg[2 * idx + 1] & seg[2 * idx + 2]);
}

int range_and(int idx, int lo, int hi, int l, int r)
{
    if (r < lo || l > hi)
        return whole;

    if (lo >= l && hi <= r)
        return seg[idx];

    int mid = (lo + hi) / 2;

    return (range_and(2 * idx + 1, lo, mid, l, r) & range_and(2 * idx + 2, mid + 1, hi, l, r));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        reset(0, 0, n - 1);
        build(0, 0, n - 1);

        int q;
        cin >> q;
        while (q--)
        {
            int l, k;
            cin >> l >> k;

            int lo = l - 1, hi = n - 1, mid;
            while (hi - lo > 1)
            {
                mid = (lo + hi) / 2;

                int ans = range_and(0, 0, n - 1, l - 1, mid);
                if (ans >= k)
                    lo = mid;
                else
                    hi = mid - 1;
            }

            if (range_and(0, 0, n - 1, l - 1, hi) >= k)
                cout << hi + 1;
            else if (range_and(0, 0, n - 1, l - 1, lo) >= k)
                cout << lo + 1;
            else
                cout << -1;

            cout << " ";
        }
        cout << endl;
    }
}