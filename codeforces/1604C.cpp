#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll lcm(ll x, ll y)
{
    return ((x * y) / __gcd(x, y));
}

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
        ll a[n + 1], l = 2;
        for (i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        bool ans = true;
        for (i = 1; i <= n; i++)
        {
            if (a[i] % l == 0)
            {
                ans = false;
                break;
            }
            l = lcm(l, i + 2);
        }
        if (ans)
            cout << "YES";
        else
            cout << "NO";

        cout << endl;
    }
}