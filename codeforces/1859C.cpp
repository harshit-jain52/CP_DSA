#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<ll> v(n);

        for (int i = 0; i < n; i++)
        {
            v[i] = i + 1;
        }

        ll sum, maxp;
        ll ans = 0;
        for (int j = n - 1; j >= 0; j--)
        {
            reverse(v.begin() + j, v.end());
            sum = 0, maxp = 0;
            for (int i = 0; i < n; i++)
            {
                sum += v[i] * (i + 1);
                maxp = max(maxp, v[i] * (i + 1));
            }

            reverse(v.begin() + j, v.end());
            ans = max(ans, sum - maxp);
        }

        cout << ans << endl;
    }
}