#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k, n, num, i;

    cin >> n >> k;

    int a[n];

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    num = a[k - 1];

    for (i = k - 1; i < n; i++)
    {
        if (a[i] != num)
            break;
    }

    if (i == n)
    {
        for (i = k - 2; i >= 0; i--)
        {
            if (a[i] != num)
                break;
        }

        cout << (i + 1);
    }
    else
    {
        cout << -1;
    }
}