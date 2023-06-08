#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q, i;
        cin >> n >> q;
        ll a[n], prefix_sum[n + 1];
        prefix_sum[0] = 0;

        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            prefix_sum[i + 1] = prefix_sum[i] + a[i];
        }

        while (q--)
        {
            int l, r;
            ll k, diff;
            cin >> l >> r >> k;

            diff = prefix_sum[n] - (prefix_sum[r] - prefix_sum[l - 1]);

            if (diff % 2 == 0)
            {
                if (k % 2 == 0 || (r - l + 1) % 2 == 0)
                {
                    cout << "NO";
                }
                else
                {
                    cout << "YES";
                }
            }
            else
            {
                if (k % 2 == 0 || (r - l + 1) % 2 == 0)
                {
                    cout << "YES";
                }
                else
                {
                    cout << "NO";
                }
            }

            cout << endl;
        }
    }
}