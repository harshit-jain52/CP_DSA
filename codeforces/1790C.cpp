#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, i, j;
    cin >> t;

    while (t--)
    {
        cin >> n;
        int a[n][n - 1];
        int first[n + 1], firstelement;

        for (i = 0; i < n + 1; i++)
        {
            first[i] = 0;
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n - 1; j++)
            {
                cin >> a[i][j];
            }
            first[a[i][0]]++;
        }

        for (i = 1; i <= n; i++)
        {
            if (first[i] > 1)
            {
                firstelement = i;
                break;
            }
        }

        for (i = 0; i < n; i++)
        {
            if (a[i][0] != firstelement)
            {
                break;
            }
        }

        cout << firstelement << " ";
        for (j = 0; j < n - 1; j++)
        {
            cout << a[i][j] << " ";
        }

        cout << endl;
    }
}