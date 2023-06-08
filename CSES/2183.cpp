#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;
    cin >> n;
    ll a[n];
    ll sum[n];

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);
    sum[0] = a[0];
    for (i = 1; i < n; i++)
    {
        sum[i] = sum[i - 1] + a[i];
    }

    if (a[0] != 1)
    {
        cout << 1;
    }
    else
    {
        for (i = 0; i < n - 1; i++)
        {
            if (sum[i] + 1 < a[i + 1])
            {
                break;
            }
        }
        cout << sum[i] + 1;
    }
}