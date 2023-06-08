#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        int a[n];

        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (i = 0; i < n; i++)
        {
            if (a[i] != a[0])
            {
                break;
            }
        }
        if (i == n)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            cout << a[0] << " ";
            for (i = n - 1; i >= 1; i--)
            {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }
}