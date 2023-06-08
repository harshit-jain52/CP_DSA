#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int main()
{
    int n, i;
    cin >> n;
    ll l[n], r[n], minl = 10e9, maxr = 1;

    for (i = 0; i < n; i++)
    {
        cin >> l[i] >> r[i];

        if (l[i] < minl)
            minl = l[i];
        if (r[i] > maxr)
            maxr = r[i];
    }

    for (i = 0; i < n; i++)
    {
        if (l[i] <= minl && r[i] >= maxr)
        {
            break;
        }
    }

    if (i == n)
    {
        cout << -1;
    }
    else
    {
        cout << (i + 1);
    }
}