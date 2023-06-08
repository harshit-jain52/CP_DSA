#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;
    ll k;
    cin >> n >> k;
    if (n == 1 && k != 0)
    {
        cout << -1;
    }
    else
    {
        if (k < n / 2)
        {
            cout << -1;
        }
        else if (k == n / 2)
        {
            for (i = 0; i < n; i++)
            {
                cout << (i + 1) << " ";
            }
        }
        else
        {
            ll num = k - n / 2 + 1;
            cout << num << " " << 2 * num << " ";
            for (i = 1; i <= n - 2; i++)
            {
                cout << 2 * num + i << " ";
            }
        }
    }
}