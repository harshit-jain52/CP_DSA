#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, d, i;
    cin >> n >> m >> d;

    int a[n * m];
    for (i = 0; i < n * m; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n * m);

    int med1 = a[(n * m) / 2], med2 = a[(n * m) / 2 - 1];

    bool flag1 = 1, flag2 = 1;
    int ct1 = 0, ct2 = 0;

    for (i = 0; i < n * m; i++)
    {
        if (abs(a[i] - med1) % d != 0)
        {
            flag1 = 0;
            break;
        }
        ct1 += (abs(a[i] - med1)) / d;
    }

    for (i = 0; i < n * m; i++)
    {
        if (abs(a[i] - med2) % d != 0)
        {
            flag2 = 0;
            break;
        }
        ct2 += (abs(a[i] - med2)) / d;
    }

    if (flag1 && !flag2)
    {
        cout << ct1;
    }
    else if (flag2 && !flag1)
    {
        cout << ct2;
    }
    else if (flag1 && flag2)
    {
        cout << min(ct1, ct2);
    }
    else
    {
        cout << -1;
    }
}