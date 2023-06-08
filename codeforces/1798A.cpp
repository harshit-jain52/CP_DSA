#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], b[n], i;

        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        if (n == 1)
        {
            cout << "Yes";
        }
        else
        {
            int minarr[n], maxarr[n];
            for (i = 0; i < n; i++)
            {
                minarr[i] = min(a[i], b[i]);
                maxarr[i] = max(a[i], b[i]);
            }

            sort(maxarr, maxarr + n - 1);
            sort(minarr, minarr + n - 1);

            if (maxarr[n - 1] >= maxarr[n - 2] && minarr[n - 1] >= minarr[n - 2])
            {
                cout << "Yes";
            }
            else
            {
                cout << "No";
            }
        }
        cout << '\n';
    }
}