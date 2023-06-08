#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isLess(ll x, ll y)
{
    return x <= y;
}
bool isMore(ll x, ll y)
{
    return x >= y;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // l <= ai + aj <= r --> l-ai <= aj <= r-ai
    int t;
    ll l, r;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n >> l >> r;
        ll a[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a, a + n);

        ll ct = 0;
        for (int i = 0; i < n-1; i++)
        {
            int idx1;
            int lo = i + 1, hi = n-1, mid;
            // FFFFTTTTT find first true
            while (hi - lo > 1)
            {
                mid = (hi + lo) / 2;

                if (isMore(a[mid], l - a[i]))
                {
                    hi = mid;
                }
                else
                {
                    lo = mid + 1;
                }
            }
            if (isMore(a[lo], l - a[i]))
            {
                idx1 = lo;
            }
            else if (isMore(a[hi], l - a[i]))
            {
                idx1 = hi;
            }
            else
            {
                continue;
            }

            int idx2;
            lo = i + 1, hi = n - 1;
            // TTTTTFFFFF find last true
            while (hi - lo > 1)
            {
                mid = (hi + lo) / 2;

                if (isLess(a[mid], r - a[i]))
                {
                    lo = mid;
                }
                else
                {
                    hi = mid - 1;
                }
            }
            if (isLess(a[hi], r - a[i]))
            {
                idx2 = hi;
            }
            else if (isLess(a[lo], r - a[i]))
            {
                idx2 = lo;
            }
            else
            {
                continue;
            }
            ct += idx2 - idx1 + 1;
        }
        cout << ct << endl;
    }
}