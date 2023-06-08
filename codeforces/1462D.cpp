#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        ll tot_sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            tot_sum += a[i];
        }

        vector<ll> factors;
        for (int i = 1; i * i <= tot_sum; i++)
        {
            if (tot_sum % i == 0)
            {
                factors.push_back(i);
                factors.push_back(tot_sum / i);
            }
        }

        int ans = n - 1;
        for (auto it : factors)
        {
            int ct = 0;
            int sub = 0;
            ll tmpsum = 0;
            bool flag = true;
            for (int i = 0; i < n; i++)
            {
                tmpsum += a[i];
                ct++;
                if (tmpsum == it)
                {
                    sub++;
                    tmpsum = 0;
                }
                else if (tmpsum > it)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                ans = min(ans, ct - sub);
            }
        }

        // for (auto it : factors)
        // {
        //     cout << it << " ";
        // }

        cout << ans << endl;
    }
}