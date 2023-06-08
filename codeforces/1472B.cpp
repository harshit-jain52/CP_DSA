#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, temp, ct1 = 0, ct0 = 0;

        cin >> n;
        for (i = 0; i < n; i++)
        {
            cin >> temp;
            if (temp == 1)
            {
                ct1++;
            }
            else
            {
                ct0++;
            }
        }

        bool ans = true;

        if (ct1 % 2 != 0)
        {
            ans = false;
        }
        else
        {
            if (ct0 % 2 != 0 && ct1 == 0)
            {
                ans = false;
            }
        }

        if (ans)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}