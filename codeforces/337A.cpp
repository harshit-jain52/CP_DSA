#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, i, diff, min_diff = 1000;
    cin >> n >> m;

    int f[m];

    for (i = 0; i < m; i++)
    {
        cin >> f[i];
    }

    sort(f, f + m);

    for (i = 0; i < m - n + 1; i++)
    {
        diff = f[i + n - 1] - f[i];
        if (diff < min_diff)
            min_diff = diff;
    }

    cout << min_diff;
}