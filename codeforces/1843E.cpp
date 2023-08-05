#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n;

bool func(int change, vector<pair<int, int>> &s, int q[])
{
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= change; i++)
    {
        a[q[i]] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        a[i] += a[i - 1];
    }

    for (auto it : s)
    {
        int l = it.first, r = it.second;
        int ct = a[r] - a[l - 1];
        if (ct > (r - l + 1) / 2)
            return true;
    }

    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m;
        cin >> n >> m;
        vector<pair<int, int>> segments(m);
        for (int i = 0; i < m; i++)
        {
            cin >> segments[i].first >> segments[i].second;
        }
        int q;
        cin >> q;
        int queries[q + 1];

        for (int i = 1; i <= q; i++)
        {
            cin >> queries[i];
        }

        int lo = 1, hi = q, mid;

        while (hi > lo)
        {
            mid = (lo + hi) / 2;

            if (func(mid, segments, queries))
                hi = mid;
            else
                lo = mid + 1;
        }

        if (func(lo, segments, queries))
            cout << lo;
        else if (func(hi, segments, queries))
            cout << hi;
        else
            cout << -1;

        cout << endl;
    }
}