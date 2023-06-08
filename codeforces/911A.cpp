#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main()
{
    int n, i, count = 0, dist, mindist;
    cin >> n;

    lli a[n], min = 10e9;
    int index[n];

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] < min)
        {
            min = a[i];
        }
    }

    for (i = 0; i < n; i++)
    {
        if (a[i] == min)
        {
            index[count] = i;
            count++;
        }
    }

    mindist = n;
    for (i = 1; i < count; i++)
    {
        dist = index[i] - index[i - 1];
        if (dist < mindist)
        {
            mindist = dist;
        }
    }

    cout << mindist;
}