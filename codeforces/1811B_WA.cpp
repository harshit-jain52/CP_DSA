#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll cell(ll x, ll y, ll n)
{
    ll i;
    bool con1, con2;
    for (i = 1; i <= n / 2; i++)
    {
        con1 = x == i || x == n - i - 1;
        con2 = y == i || y == n - i - 1;
        if (con1 && con2)
        {
            return i;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll n, x1, y1, x2, y2;
        cin >> n >> x1 >> y1 >> x2 >> y2;

        cout << abs(cell(x1, y1, n) - cell(x2, y2, n)) << endl;
    }
}