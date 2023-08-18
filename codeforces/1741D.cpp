#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

bool isPossible;
int func(int lo, int hi, int p[])
{
    if (lo >= hi)
        return 0;

    int mid = (lo + hi) / 2;

    int minLeft, minRight, maxLeft, maxRight;
    minLeft = minRight = 1e7;
    maxLeft = maxRight = 0;

    for (int i = lo; i <= mid; i++)
    {
        minLeft = min(minLeft, p[i]);
        maxLeft = max(maxLeft, p[i]);
    }

    for (int i = mid + 1; i <= hi; i++)
    {
        minRight = min(minRight, p[i]);
        maxRight = max(maxRight, p[i]);
    }

    if (maxLeft < minRight)
    {
        return (func(lo, mid, p) + func(mid + 1, hi, p));
    }
    else if (maxRight < minLeft)
    {
        return (1 + func(lo, mid, p) + func(mid + 1, hi, p));
    }
    else
    {
        isPossible = false;
        return 0;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        isPossible = true;
        int m;
        cin >> m;
        int p[m];
        for (int i = 0; i < m; i++)
        {
            cin >> p[i];
        }

        int ans = func(0, m - 1, p);

        if (isPossible)
            cout << ans;
        else
            cout << -1;

        cout << endl;
    }
}