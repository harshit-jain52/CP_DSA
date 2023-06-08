#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, i, temp, minc = 101, maxc = 0, minw = 101;

    cin >> n >> m;

    for (i = 0; i < n; i++)
    {
        cin >> temp;
        if (temp < minc)
        {
            minc = temp;
        }
        if (temp > maxc)
        {
            maxc = temp;
        }
    }
    for (i = 0; i < m; i++)
    {
        cin >> temp;
        if (temp < minw)
        {
            minw = temp;
        }
    }

    if (maxc < minw)
    {
        for (i = maxc; i < minw; i++)
        {
            if (2 * minc <= i)
            {
                break;
            }
        }

        if (i == minw)
        {
            cout << -1;
        }
        else
        {
            cout << i;
        }
    }
    else
    {
        cout << -1;
    }
}