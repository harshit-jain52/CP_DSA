#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, prod = 1, count0 = 0;
    cin >> n;
    ll a[n], ct = 0;

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > 0)
        {
            ct += a[i] - 1;
        }
        else if (a[i] < 0)
        {
            ct += (-1 - a[i]);
            prod *= (-1);
        }
        else
        {
            count0++;
        }
    }

    if (prod == 1 || count0 > 0)
    {
        cout << ct + count0;
    }
    else
    {
        cout << ct + 2;
    }
}