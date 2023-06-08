#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, count = 1, maxcount = 1;

    cin >> n;
    int h[n], m[n];

    for (i = 0; i < n; i++)
    {
        cin >> h[i] >> m[i];
    }

    for (i = 1; i < n; i++)
    {
        if (h[i] == h[i - 1] && m[i] == m[i - 1])
        {
            count++;
        }
        else
        {
            if (count > maxcount)
            {
                maxcount = count;
            }

            count = 1;
        }
    }
    if (count > maxcount)
    {
        maxcount = count;
    }

    cout << maxcount;
}