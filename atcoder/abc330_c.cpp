#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll d;
    cin >> d;

    ll ans = d;
    ll lim = sqrt(d);

    for (ll x = 0; x <= lim; x++)
    {
        ll lo = 0, hi = lim, y;

        while (lo <= hi)
        {
            y = (lo + hi) / 2;

            ll val = x * x + y * y - d;
            ans = min(ans, abs(val));

            if (val > 0)
                hi = y - 1;
            else if (val < 0)
                lo = y + 1;
            else
                break;
        }

        if (ans == 0)
            break;
    }

    cout << ans;
}