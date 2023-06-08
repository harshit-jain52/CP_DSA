#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, j, count = 0;
    cin >> n;
    int a[n], b[n];

    for (i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j == i)
                continue;

            if (b[j] == a[i])
            {
                break;
            }
        }

        if (j == n)
        {
            count++;
        }
    }

    cout << count;
}