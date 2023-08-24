#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

ll calc(ll num)
{
    return num * (num - 1) / 2;
}

ll lowerBound(ll x)
{
    ll lo = 1, hi = INT_MAX, mid;

    while (hi - lo > 1)
    {
        mid = (lo + hi) / 2;

        if (calc(mid) >= x)
            hi = mid;
        else
            lo = mid + 1;
    }

    if (calc(lo) >= x)
        return lo;
    else
        return hi;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll ans = lowerBound(n);

        if (calc(ans) == n)
            cout << ans;
        else
            cout << (ans - 1 + n - calc(ans - 1));
        cout << endl;
    }
}