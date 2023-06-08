#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, earn = 0;
    cin >> n >> m;
    int a[n], i;

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    for (i = 0; i < m; i++)
    {
        if (a[i] >= 0)
        {
            break;
        }
        earn -= a[i];
    }

    cout << earn;
}