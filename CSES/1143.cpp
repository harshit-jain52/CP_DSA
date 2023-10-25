#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;
const int N = 2e5 + 10;

ll arr[N], seg[4 * N];

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

    seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
}

void update(int idx, int lo, int hi, ll val, int &getHotel)
{
    if (lo > hi)
        return;

    if (seg[idx] < val)
    {
        getHotel = 0;
        return;
    }

    if (lo == hi)
    {
        seg[idx] -= val;
        getHotel = lo + 1;
        return;
    }

    int mid = (lo + hi) / 2;
    if (seg[2 * idx + 1] >= val)
        update(2 * idx + 1, lo, mid, val, getHotel);
    else
        update(2 * idx + 2, mid + 1, hi, val, getHotel);

    seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    build(0, 0, n - 1);

    int i = 0;
    while (m--)
    {
        ll r;
        cin >> r;

        update(0, 0, n - 1, r, i);
        cout << i << " ";
    }
}