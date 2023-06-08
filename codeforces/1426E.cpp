#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, minwin, maxwin, i, j;
    cin >> n;
    long long a[4], b[4];
    cin >> a[0] >> a[1] >> a[2];
    cin >> b[0] >> b[1] >> b[2];
    a[3] = a[0];
    b[3] = b[0];

    maxwin = 0;
    for (i = 0; i < 3; i++)
    {
        maxwin += min(a[i], b[i + 1]);
    }

    
    minwin = n;
    for (i = 0; i < 3; i++)
    {
        minwin -= min(b[i], a[i] + a[i + 1]);
    }

    cout << minwin << " " << maxwin;
}