#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;
    cin >> n;
    ll a[n];

    // Kadane's Algo

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll ans = -1e9, maxsofar = a[0];

    for (i = 1; i < n; i++)
    {
        if (maxsofar > ans)
        {
            ans = maxsofar;
        }

        if (maxsofar < 0)
        {
            maxsofar = 0;
        }

        maxsofar += a[i];
    }
    if (maxsofar > ans)
    {
        ans = maxsofar;
    }

    cout << ans;
}