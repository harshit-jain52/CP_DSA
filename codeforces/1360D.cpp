#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll n, k, ans;
        cin >> n >> k;
        ans = n;
        for (ll i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                if (i <= k)
                    ans = min(ans, n / i);
                if (n / i <= k)
                    ans = min(ans, i);
            }
        }

        cout << ans << endl;
    }
}