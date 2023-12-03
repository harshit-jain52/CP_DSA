#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int seg[4 * N];

int range_sum(int idx, int lo, int hi, int l, int r)
{
    if (r < lo || l > hi)
        return 0;

    if (lo >= l && hi <= r)
        return seg[idx];

    int mid = (lo + hi) / 2;

    return range_sum(2 * idx + 1, lo, mid, l, r) + range_sum(2 * idx + 2, mid + 1, hi, l, r);
}

void point_update(int idx, int lo, int hi, int i, ll val)
{
    if (lo == hi)
    {
        seg[idx] += val;
        return;
    }

    int mid = (lo + hi) / 2;

    if (i <= mid)
        point_update(2 * idx + 1, lo, mid, i, val);
    else
        point_update(2 * idx + 2, mid + 1, hi, i, val);

    seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<pair<pair<int, int>, int>> vec(q);
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        vec[i] = {{r, l}, i};
    }
    sort(vec.begin(), vec.end());

    map<int, int> lastIdx;
    int curr = 0, ans[q];

    for (int i = 0; i < n && curr < q; i++)
    {
        if (lastIdx.find(a[i]) != lastIdx.end())
        {
            point_update(0, 0, n - 1, lastIdx[a[i]], -1);
        }
        lastIdx[a[i]] = i;
        point_update(0, 0, n - 1, lastIdx[a[i]], 1);

        while (vec[curr].first.first == i && curr < q)
        {
            ans[vec[curr].second] = range_sum(0, 0, n - 1, vec[curr].first.second, vec[curr].first.first);
            curr++;
        }
    }

    for (int i = 0; i < q; i++)
    {
        cout << ans[i] << endl;
    }
}