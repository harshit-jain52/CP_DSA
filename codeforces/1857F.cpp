#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll a[n];
        map<ll, ll> ct;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            ct[a[i]]++;
        }

        int q;
        cin >> q;
        while (q--)
        {
            ll x, y;
            cin >> x >> y;

            ll D = x * x - 4 * y;
            if (D < 0)
            {
                cout << 0;
            }
            else
            {
                ll rootD = sqrt(D);
                if (rootD * rootD != D)
                {
                    cout << 0;
                }
                else
                {
                    ll num1 = x + rootD, num2 = x - rootD;
                    if (num1 % 2 == 1 || num2 % 2 == 1)
                    {
                        cout << 0;
                    }
                    else
                    {
                        if (num1 == num2)
                            cout << ct[num1 / 2] * (ct[num1 / 2] - 1) / 2;
                        else
                            cout << ct[num1 / 2] * ct[num2 / 2];
                    }
                }
            }
            cout << " ";
        }
        cout << endl;
    }
}