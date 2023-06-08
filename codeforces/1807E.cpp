#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int lo = 0, hi = n - 1, mid;
        while (true)
        {
            ll sum = 0;
            mid = (lo + hi) / 2;
            cout << "? " << mid - lo + 1 << " ";
            for (i = lo; i <= mid; i++)
            {
                sum += a[i];
                cout << i + 1 << " ";
            }
            cout << endl
                 << endl
                 << flush;
            ll x;
            cin >> x;

            if (sum < x)
            {
                if (lo == mid)
                {
                    cout << "! " << lo + 1;
                    break;
                }
                else
                {
                    hi = mid;
                }
            }
            else
            {
                lo = mid+1;
            }
        }
        cout << endl
             << endl
             << flush;
    }
}