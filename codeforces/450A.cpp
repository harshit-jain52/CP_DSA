#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, max = 0, posofmax, i;

    cin >> n >> m;
    int a[n];
    int times[n];

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        times[i] = (a[i] / m) + (int)(a[i] % m != 0);
    }

    for (i = 0; i < n; i++)
    {
        if (times[i] >= max)
        {
            max = times[i];
            posofmax = i + 1;
        }
    }

    cout << posofmax;
}