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
        int n, i, flag = 0;
        cin >> n;
        ll a[n];

        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] <= (i + 1))
            {
                flag = 1;
            }
        }

        if (flag)
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
}