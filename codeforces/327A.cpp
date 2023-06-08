#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, count0 = 0, count1 = 0, totalcount1 = 0, totalcount0 = 0, max = 0;
    cin >> n;
    int a[n];

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
        {
            totalcount1++;
        }
        else
        {
            totalcount0++;
        }
    }
    if (totalcount0)
    {
        for (i = 0; i < n; i++)
        {
            if (a[i] == 0)
            {
                count0++;
            }
            else
            {
                count1++;
            }

            if (count1 >= count0)
            {
                count0 = count1 = 0;
            }
            else
            {
                if (count0 - count1 > max)
                {
                    max = count0 - count1;
                }
            }
        }

        cout << max + totalcount1;
    }
    else
    {
        cout << totalcount1 - 1;
    }
}