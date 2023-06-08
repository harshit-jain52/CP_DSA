#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    ll a[n];
    ll num = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        num = __gcd(num, a[i]);
    }

    ll tot = 0;

    for (ll i = 1; i * i <= num; i++)
    {
        if (i * i == num)
        {
            tot++;
        }
        else
        {
            if (num % i == 0)
            {
                tot += 2;
            }
        }
    }

    cout << tot;
}