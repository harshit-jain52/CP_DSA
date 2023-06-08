#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        int a[n][n], i, j;

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }

        ll ct = 0;

        if (n % 2 != 0)
        {
            for (j = 0; j < n / 2; j++)
            {
                if (a[n / 2][j] != a[n / 2][n - 1 - j])
                {
                    ct++;
                }
            }
        }

        for (i = 0; i < n / 2; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (a[i][j] != a[n - 1 - i][n - 1 - j])
                {
                    ct++;
                }
            }
        }

        if (k < ct)
        {
            cout << "NO";
        }
        else
        {
            if (n % 2 == 1 || ((k - ct) % (n * n)) % 2 == 0)
            {
                cout << "YES";
            }
            else
            {
                cout << "NO";
            }
        }

        cout << endl;
    }
}