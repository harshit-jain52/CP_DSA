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
        ll a, b, n, m;
        cin >> a >> b >> n >> m;
        if (a + b < n + m)
            cout << "NO";
        else
        {
            if (a > b)
            {
                ll x = min(a - b, n);
                n = n - x;
                a = a - x;
            }
            else if (b > a)
            {
                ll x = min(b - a, n);
                n = n - x;
                b = b - x;
            }

            // now b=a or n=0 or both

            if (n >= m || min(a, b) >= m)
                cout << "YES";
            else
                cout << "NO";
        }
        cout << endl;
    }
}