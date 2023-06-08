#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        ll a[n], b[n], ans;

        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        sort(a, a + n);
        sort(b, b + n);

        ans = (a + n) - upper_bound(a, a + n, b[n - 1]);

        for (i = n - 2; i >= 0; i--)
        {
            ll tmp = (a + n) - upper_bound(a, a + n, b[i]);
            ans = ((ans % M) * ((tmp - (n - 1 - i)) % M)) % M;
        }

        cout << ans << endl;
    }
}