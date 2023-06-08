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
        int n, m, i;
        cin >> n >> m;
        ll a[n];
        vector<int> r(m);

        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            r[a[i] % m]++;
        }
        int ct = 0, m1, m2;

        if (r[0] > 0)
        {
            ct++;
        }

        for (i = 1; i <= m / 2 - (int)(m % 2 == 0); i++)
        {
            m1 = max(r[i], r[m - i]);
            m2 = min(r[i], r[m - i]);

            if (m1 - m2 <= 1 && m1 > 0)
            {
                ct++;
            }
            else
            {
                ct += m1 - m2;
            }
        }

        if (m % 2 == 0 && r[m / 2] > 0)
        {
            ct++;
        }

        cout << ct << endl;
    }
}