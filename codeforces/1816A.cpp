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
        ll a, b, g;
        cin >> a >> b;
        g = __gcd(a, b);

        if (g == 1)
        {
            cout << 1 << endl;
            cout << a << " " << b << endl;
        }
        else
        {
            cout << 2 << endl;
            cout << 1 << " " << b - 1 << endl;
            cout << a << " " << b << endl;
        }
    }
}