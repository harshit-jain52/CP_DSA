#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
S/n = (S-x)/(n-2)
--> 2S = nx

S = sum of all elements
x = sum of pair of elements to be removed
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, i, j;
        cin >> n;
        ll sum = 0, a[n];
        map<ll, ll> m;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
            m[a[i]]++;
        }

        if ((2 * sum) % n == 0)
        {
            ll x = (2 * sum) / n;

            // cout << x << endl;
            ll ct = 0;
            sort(a, a + n);
            i = 0, j = n - 1;
            while (i < j)
            {
                if (i != 0 && a[i] == a[i - 1])
                {
                    i++;
                    continue;
                }
                if (j != n - 1 && a[j] == a[j + 1])
                {
                    j--;
                    continue;
                }

                if (a[i] + a[j] < x)
                {
                    i++;
                    continue;
                }

                if (a[i] + a[j] > x)
                {
                    j--;
                    continue;
                }

                if (x % 2 == 0 && a[i] == x / 2)
                {
                    ct += m[a[i]] * (m[a[i]] - 1) / 2;
                }
                else
                {
                    ct += m[a[i]] * m[a[j]];
                }
                i++;
                j--;
            }

            cout << ct << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
}