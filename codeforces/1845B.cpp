#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll xa, ya, xb, yb, xc, yc;
        ll ans = 1;
        cin >> xa >> ya >> xb >> yb >> xc >> yc;
        if ((xb - xa) * (xc - xa) > 0)
        {
            ans += min(abs(xb - xa), abs(xc - xa));
        }
        if ((yb - ya) * (yc - ya) > 0)
        {
            ans += min(abs(yb - ya), abs(yc - ya));
        }

        cout << ans << endl;
    }
}