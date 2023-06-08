#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, minm, maxm, i;
    cin >> n >> m;

    maxm = n;
    minm = n / 2 + n % 2;

    for (i = minm; i <= maxm; i++)
    {
        if (i % m == 0)
        {
            break;
        }
    }

    if (i == maxm + 1)
    {
        cout << -1;
    }
    else
    {
        cout << i;
    }
}