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

        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        bool flag = true;

        if (n != 1)
        {
            if (n == 2)
            {
                if (a[0] == 0 && a[1] == 0)
                {
                    flag = false;
                }
            }
            else
            {
                for (i = 0; i < n / 2 + n % 2; i++)
                {
                    if (a[i] < i || a[n - 1 - i] < i)
                    {
                        flag = false;
                        break;
                    }
                }
                if (n % 2 == 0)
                {
                    if (a[n / 2 - 1] == n / 2 - 1 && a[n / 2] == n / 2 - 1)
                    {
                        flag = false;
                    }
                }
            }
        }

        if (flag)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}