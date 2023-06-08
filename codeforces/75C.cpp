#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll a, b;
    cin >> a >> b;
    ll g = __gcd(a, b);

    set<ll> factors;
    for (ll i = 1; i * i <= g; i++)
    {
        if (g % i == 0)
        {
            factors.insert(i);
            factors.insert(g / i);
        }
    }

    int n;
    cin >> n;

    while (n--)
    {
        ll low, high;
        cin >> low >> high;

        if (low > g)
        {
            cout << -1;
        }
        else
        {
            auto it = lower_bound(factors.begin(), factors.end(), high);
            if (it == factors.end())
                cout << g;
            else
            {
                if (*it == high)
                    cout << high;
                else
                {
                    --it;
                    if (*it >= low)
                        cout << *it;
                    else
                        cout << -1;
                }
            }
        }
        cout << endl;
    }
}