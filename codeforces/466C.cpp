#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;
    cin >> n;

    ll a[n], asum[n + 1];
    asum[0] = 0;

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        asum[i + 1] = asum[i] + a[i];
    }

    if (asum[n] % 3 != 0 || n < 3)
    {
        cout << 0;
    }
    else if (asum[n] != 0)
    {
        ll count3 = 0, total = 0, count1 = 0;
        for (i = n; i >= 3; i--)
        {
            if (asum[i] != asum[n])
            {
                break;
            }
            count3++;
        }

        for (i = 1; i <= n; i++)
        {
            if (asum[i] == 2 * asum[n] / 3)
            {
                total += count1;
            }
            if (asum[i] == asum[n] / 3)
            {
                count1++;
            }
        }

        total *= count3;

        cout << total;
    }
    else
    {
        ll count0 = count(asum + 1, asum + n + 1, 0);
        if (count0 < 3)
        {
            cout << 0;
        }
        else
        {
            cout << (count0 - 1) * (count0 - 2) / 2; //(count0-1)C(2)
        }
    }
}