#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll power10(int x)
{
    ll ans = 1;
    for (int i = 1; i <= x; i++)
    {
        ans *= 10;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        ll k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        ll mx = 0;
        int idx = n;
        for (int i = 0; i < n; i++)
        {
            ll num = power10(a[i]) - 1;
            ll req = 0;
            for (int j = 0; j < i; j++)
            {
                req += power10(a[j + 1] - a[j]) - 1;
            }
            // cout << req << endl;
            if (k >= req && num <= mx)
            {

                num += (k - req) * power10(a[i]);
                mx = max(mx, num);
                // cout << mx << endl;
            }
            else
            {
                idx = i;
                break;
            }
        }
        mx += power10(a[idx - 1]) - 1;

        cout << (mx + 1) << endl;
    }
}