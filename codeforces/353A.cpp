#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, sumx = 0, sumy = 0, i;

    cin >> n;
    int x[n], y[n];

    for (i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        sumx += x[i];
        sumy += y[i];
    }

    if (sumx % 2 == 0 && sumy % 2 == 0)
    {
        cout << 0;
    }
    else if (sumx % 2 && sumy % 2)
    {
        for (i = 0; i < n; i++)
        {
            if ((x[i] % 2 == 0 && y[i] % 2 == 1) || (y[i] % 2 == 0 && x[i] % 2 == 1))
            {
                cout << 1;
                break;
            }
        }
        if (i == n)
        {
            cout << -1;
        }
    }
    else
    {
        cout << -1;
    }
}