#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, l, r;
    cin >> n;
    long long a[n];

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            l = i;
            break;
        }
    }

    if (i == n - 1)
    {
        l = 0;
        r = 0;
        goto yes;
    }

    for (i = l; i < n - 1; i++)
    {
        if (a[i] < a[i + 1])
        {
            r = i;
            break;
        }
    }
    if (i == n - 1)
    {
        r = n - 1;
    }

    for (i = r + 1; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            break;
        }
    }

    if ((r < n - 1) && (a[r + 1] < a[l]) || i < n - 1 || (l > 0) && (a[l - 1] > a[r]))
    {
        cout << "no";
    }
    else
    {
    yes:
        cout << "yes" << endl
             << l + 1 << " " << r + 1;
    }
}