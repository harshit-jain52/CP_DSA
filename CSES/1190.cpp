#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

const int N = 2e5 + 10;

ll arr[N];

ll totalSum[4 * N];
ll maxSubarraySum[4 * N];
ll maxPref[4 * N];
ll maxSuff[4 * N];

void build(int idx, int lo, int hi)
{
    if (lo > hi)
        return;
    if (lo == hi)
    {
        totalSum[idx] = arr[lo];
        maxSubarraySum[idx] = arr[lo];
        maxPref[idx] = arr[lo];
        maxSuff[idx] = arr[lo];
        return;
    }

    int mid = (lo + hi) / 2;
    int left = 2 * idx + 1, right = 2 * idx + 2;

    build(left, lo, mid);
    build(right, mid + 1, hi);

    totalSum[idx] = totalSum[left] + totalSum[right];
    maxPref[idx] = max(0LL, max(maxPref[left], totalSum[left] + maxPref[right]));
    maxSuff[idx] = max(0LL, max(maxSuff[right], totalSum[right] + maxSuff[left]));
    maxSubarraySum[idx] = max(max(maxSubarraySum[left], maxSubarraySum[right]), max(0LL, maxPref[right] + maxSuff[left]));
}

void point_update(int idx, int lo, int hi, int i, ll val)
{
    if (lo == hi)
    {
        totalSum[idx] = val;
        maxSubarraySum[idx] = val;
        maxPref[idx] = val;
        maxSuff[idx] = val;
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
    maxSuff[idx] = max(0LL, max(maxSuff[right], totalSum[right] + maxSuff[left]));
    maxSubarraySum[idx] = max(max(maxSubarraySum[left], maxSubarraySum[right]), max(0LL, maxPref[right] + maxSuff[left]));
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
        int k;
        ll x;

        cin >> k >> x;

        point_update(0, 0, n - 1, k - 1, x);
        cout << max(0LL, maxSubarraySum[0]) << endl;
    }
}