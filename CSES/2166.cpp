#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<ll, ll> pll;

const int N = 2e5 + 10;
ll arr[N];
ll totalSum[4 * N];
ll maxPref[4 * N];

void build(int idx, int lo, int hi)
{
    if (lo > hi)
        return;
    if (lo == hi)
    {
        totalSum[idx] = arr[lo];
        maxPref[idx] = arr[lo];
        return;
    }

    int mid = (lo + hi) / 2;
    int left = 2 * idx + 1, right = 2 * idx + 2;

    build(left, lo, mid);
    build(right, mid + 1, hi);

    totalSum[idx] = totalSum[left] + totalSum[right];
    maxPref[idx] = max(0LL, max(maxPref[left], totalSum[left] + maxPref[right]));
}

void point_update(int idx, int lo, int hi, int i, ll val)
{
    if (lo == hi)
    {
        totalSum[idx] = val;
        maxPref[idx] = val;
        return;
    }

    int mid = (lo + hi) / 2;
    int left = 2 * idx + 1, right = 2 * idx + 2;

    if (i <= mid)
        point_update(left, lo, mid, i, val);
    else
        point_update(right, mid + 1, hi, i, val);

    totalSum[idx] = totalSum[left] + totalSum[right];
    maxPref[idx] = max(0LL, max(maxPref[left], totalSum[left] + maxPref[right]));
}

pll query(int idx, int lo, int hi, int l, int r)
{
    if (lo > hi || l > hi || r < lo)
        return {0, 0};

    if (l <= lo && r >= hi)
        return {maxPref[idx], totalSum[idx]};

    int mid = (lo + hi) / 2;
    pll left = query(2 * idx + 1, lo, mid, l, r);
    pll right = query(2 * idx + 2, mid + 1, hi, l, r);

    return {max(left.first, left.second + right.first), left.second + right.second};
}

int main()
{
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
            ll u;
            cin >> k >> u;
            point_update(0, 0, n - 1, k - 1, u);
        }
        else
        {
            int a, b;
            cin >> a >> b;
            cout << max(0LL, query(0, 0, n - 1, a - 1, b - 1).first) << endl;
        }
    }
}