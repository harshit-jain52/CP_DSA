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
        ll a[n], max1 = 0, max2 = 0;

        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] >= max1)
            {
                max2 = max1;
                max1 = a[i];
            }
            else if (a[i] >= max2)
            {
                max2 = a[i];
            }
        }

        for (i = 0; i < n; i++)
        {
            if (a[i] == max1)
            {
                cout << (a[i] - max2) << " ";
            }
            else
            {
                cout << (a[i] - max1) << " ";
            }
        }

        cout << endl;
    }
}