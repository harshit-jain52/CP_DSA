#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll x;
    cin >> x;
    pair<ll, ll> p;

    for (ll i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            if (__gcd(i, x / i) == 1)
            {
                p = {i, x / i};
            }
        }
    }

    cout << p.first << " " << p.second;
}