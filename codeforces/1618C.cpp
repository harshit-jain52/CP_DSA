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
        int n, i;
        cin >> n;
        ll a[n], g1 = 0, g2 = 0;

        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (i = 0; i < n; i++)
        {
            if (i & 1)
            {
                g1 = __gcd(g1, a[i]);
            }
            else
            {
                g2 = __gcd(g2, a[i]);
            }
        }

        int flag = 0;

        for (i = 0; i < n; i++)
        {
            if (i % 2 == 1)
            {
                if (a[i] % g2 == 0)
                {
                    break;
                }
            }
        }

        if (i == n)
        {
            cout << g2;
            flag = 1;
        }
        else
        {
            for (i = 0; i < n; i++)
            {
                if (i % 2 == 0)
                {
                    if (a[i] % g1 == 0)
                    {
                        break;
                    }
                }
            }

            if (i == n)
            {
                cout << g1;
                flag = 1;
            }
        }

        if (flag == 0)
        {
            cout << 0;
        }

        cout << endl;
    }
}