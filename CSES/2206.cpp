#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;
const int N = 2e5 + 10;

ll arr[N], leftseg[4 * N], rightseg[4 * N];

void build(int idx, int lo, int hi)
{
    if (lo > hi)
        return;

    if (lo == hi)
    {
        leftseg[idx] = arr[lo] - lo;
        rightseg[idx] = arr[lo] + lo;
        return;
    }

    int mid = (lo + hi) / 2;

    build(2 * idx + 1, lo, mid);
    build(2 * idx + 2, mid + 1, hi);

    leftseg[idx] = min(leftseg[2 * idx + 1], leftseg[2 * idx + 2]);
    rightseg[idx] = min(rightseg[2 * idx + 1], rightseg[2 * idx + 2]);
}

void update(int idx, int lo, int hi, int pos, ll newPrice)
{
    if (lo > hi)
        return;

    if (lo == hi)
    {
        leftseg[idx] = newPrice - lo;
        rightseg[idx] = newPrice + lo;
        return;
    }

    int mid = (lo + hi) / 2;
    if (pos <= mid)
        update(2 * idx + 1, lo, mid, pos, newPrice);
    else
        update(2 * idx + 2, mid + 1, hi, pos, newPrice);

    leftseg[idx] = min(leftseg[2 * idx + 1], leftseg[2 * idx + 2]);
    rightseg[idx] = min(rightseg[2 * idx + 1], rightseg[2 * idx + 2]);
}

ll minQuery(int idx, int lo, int hi, int l, int r, bool isLeft)
{
    if (lo >= l && hi <= r)
    {
        if (isLeft)
            return leftseg[idx];
        else
            return rightseg[idx];
    }

    if (hi < l || lo > r)
        return INT_MAX;

    int mid = (lo + hi) / 2;
    return min(minQuery(2 * idx + 1, lo, mid, l, r, isLeft), minQuery(2 * idx + 2, mid + 1, hi, l, r, isLeft));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    build(0, 0, n - 1);

    while (q--)
    {
        int c;
        cin >> c;

        if (c == 1)
        {
            int k;
            ll x;

            cin >> k >> x;

            update(0, 0, n - 1, k - 1, x);
        }
        else
        {
            int k;
            cin >> k;

            k=k-1;

            cout << min(k + minQuery(0, 0, n - 1, 0, k, true), minQuery(0, 0, n - 1, k, n - 1, false) - k) << endl;
        }
    }
}