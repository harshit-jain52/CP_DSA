#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

ll func(ll a[], int k, int idx, ll upper)
{
    int i = idx;
    ll ans = upper;
    while (a[i] <= ans && i >= 0)
    {
        ll diff = ans - a[i];
        if (diff + 1 > k)
            break;

        ans = a[i] + diff + 1;
        k = k - (diff + 1);
        i--;
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        ll a[n], maxelem = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            maxelem = max(maxelem, a[i]);
        }

        ll ans = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            if (a[i + 1] == maxelem)
            {
                ans = max(ans, func(a, k, i, maxelem));
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (a[i] == maxelem)
            {
                for (int j = i + 1; j < n - 2; j++)
                {
                    if (a[j + 1] <= a[j] && a[j] <= a[j + 2])
                    {
                        int diff = a[j] - a[j + 1];
                        if (k >= diff)
                        {
                            ans = max(ans, func(a, k - diff, j, a[j]));
                        }
                        break;
                    }
                }
            }
        }

        cout << ans << endl;
    }
}