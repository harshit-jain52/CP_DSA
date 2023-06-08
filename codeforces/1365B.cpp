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
        int n, i, flag = 1, ct0 = 0, ct1 = 0;
        cin >> n;
        ll a[n];
        int b[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (i = 0; i < n; i++)
        {
            cin >> b[i];
            if (b[i] == 1)
            {
                ct1++;
            }
            else
            {
                ct0++;
            }
        }

        for (i = 1; i < n; i++)
        {
            if (a[i] < a[i - 1])
            {
                flag = 0;
                break;
            }
        }

        if (flag || ct1 && ct0)
        {
            cout << "Yes";
        }
        else
        {
            cout << "No";
        }
        cout << endl;
    }
}