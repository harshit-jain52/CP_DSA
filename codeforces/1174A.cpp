#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i;
    cin >> n;
    int a[2 * n];

    for (i = 0; i < 2 * n; i++)
    {
        cin >> a[i];
    }
    for (i = 0; i < 2 * n; i++)
    {
        if (a[i] != a[0])
        {
            break;
        }
    }

    if (i == 2 * n)
    {
        cout << -1;
    }
    else
    {
        sort(a, a + 2 * n);
        for (i = 0; i < 2 * n; i++)
        {
            cout << a[i] << " ";
        }
    }
}