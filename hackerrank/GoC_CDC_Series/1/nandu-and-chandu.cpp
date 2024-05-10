#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll x, a, b;
    cin >> x >> a >> b;
    ll lcm = (a * b) / __gcd(a, b);
    cout << (x + lcm);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}