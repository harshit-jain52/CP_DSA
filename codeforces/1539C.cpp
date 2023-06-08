#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;
    ll k, x, diff;

    cin >> n >> k >> x;

    ll a[n], to_insert[n];

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);
    to_insert[0] = 0;
    for (i = 1; i < n; i++)
    {
        diff = a[i] - a[i - 1];

        to_insert[i] = diff / x - (int)(diff != 0 && diff % x == 0);
    }

    sort(to_insert, to_insert + n);

    for (i = 0; i < n; i++)
    {
        if (k == 0)
        {
            break;
        }

        if (k >= to_insert[i])
        {
            k -= to_insert[i];
            to_insert[i] = 0;
        }
        else
        {
            k = 0;
        }
    }

    int ct = 0;
    for (i = 0; i < n; i++)
    {
        if (to_insert[i] > 0)
        {
            ct++;
        }
    }

    cout << (ct + 1);
}