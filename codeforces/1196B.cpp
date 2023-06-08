#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    while (q--)
    {
        int n, k, i, oddct = 0;
        cin >> n >> k;
        ll a[n];

        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] % 2 == 1)
            {
                oddct++;
            }
        }

        if (oddct >= k && (oddct - k) % 2 == 0)
        {
            cout << "YES" << endl;
            int ct;
            for (i = 0, ct = 1; i < n && ct <= k - 1; i++)
            {
                if (a[i] % 2 == 1)
                {
                    cout << (i + 1) << " ";
                    ct++;
                }
            }
            cout << n << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}