#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll k, x;

bool canSend(ll n)
{
    ll num;
    if (n <= k)
    {
        num = n * (n + 1) / 2;
    }
    else
    {
        num = k * (k + 1) / 2 + (k - 1) * k / 2 - (2 * k - n - 1) * (2 * k - n) / 2;
    }
    return (num < x);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> k >> x;
        ll lo = 1, hi = 2 * k - 1, mid;
        // TTTTTFFFF find first F

        while (hi - lo > 1)
        {
            mid = (hi + lo) / 2;

            if (canSend(mid))
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid;
            }
        }

        if (!canSend(lo))
        {
            cout << lo << endl;
        }
        else
        {
            cout << hi << endl;
        }
    }
}