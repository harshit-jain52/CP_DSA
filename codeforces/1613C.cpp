#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100;
int n;
ll a[N], h;

bool isEnough(ll k)
{
    ll damage = 0;
    for (int i = 1; i < n; i++)
    {
        damage += min(k, a[i] - a[i - 1]);
    }
    damage += k;

    return (damage >= h);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int i;
        cin >> n >> h;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        ll lo = 0, hi = 1e18 + 1, mid;
        while (hi - lo > 1)
        { // FFFFFFTTTT
            mid = (hi + lo) / 2;

            if (isEnough(mid))
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }

        if (isEnough(lo))
        {
            cout << lo;
        }
        else
        {
            cout << hi;
        }

        cout << endl;
    }
}