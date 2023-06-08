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
        ll a[n];
        int rem[n];

        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            rem[i] = a[i] % 3;
        }

        int ct0 = 0, ct1 = 0, ct2 = 0;

        for (i = 0; i < n; i++)
        {
            switch (rem[i])
            {
            case 0:
                ct0++;
                break;
            case 1:
                ct1++;
                break;
            case 2:
                ct2++;
                break;
            }
        }

        cout << (ct0 + min(ct1, ct2) + (max(ct1, ct2) - min(ct1, ct2)) / 3) << endl;
    }
}