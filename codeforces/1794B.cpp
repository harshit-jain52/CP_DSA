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
        int n, i;
        cin >> n;
        ll a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (i = 0; i < n; i++)
        {
            if (a[i] == 1)
            {
                a[i]++;
            }
        }

        for (i = 1; i < n; i++)
        {
            if (a[i] % a[i - 1] == 0)
            {
                a[i]++;
            }
        }

        for (i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        cout << endl;
    }
}