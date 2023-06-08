#include <bits/stdc++.h>
using namespace std;

int main()
{
    int s, n, i, j;

    cin >> s >> n;

    int x[n], y[n];

    for (i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (x[j] > x[j + 1])
            {
                swap(x[j], x[j + 1]);
                swap(y[j], y[j + 1]);
            }
        }
    }

    i = 0;
    while (s > x[i] && i < n)
    {
        s += y[i];
        i++;
    }

    if (i == n)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}