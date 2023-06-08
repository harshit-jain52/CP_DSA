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
        int n, i, j;
        ll ct = 0;
        cin >> n;
        ll a[n + 1];
        for (i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        for (i = 1; i <= n; i++)
        {
            for (j = a[i] - i; j <= n; j += a[i])
            {
                if (i < j && a[i] * a[j] == i + j)
                {
                    ct++;
                }
            }
        }

        cout << ct << endl;
    }
}