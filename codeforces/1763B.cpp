#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        ll h[n], p[n];

        for (int i = 0; i < n; i++)
        {
            cin >> h[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
        }

        vector<pair<ll, ll>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({h[i], p[i]});
        }
        sort(h, h + n);
        sort(v.begin(), v.end());

        ll minPowerRight[n];
        minPowerRight[n - 1] = v[n - 1].second;
        for (int i = n - 2; i >= 0; i--)
        {
            minPowerRight[i] = min(v[i].second, minPowerRight[i + 1]);
        }

        int attackleft = k, totdamage = 0;

        while (attackleft > 0)
        {
            totdamage += attackleft;
            auto it = upper_bound(h, h + n, totdamage) - h;
            if (it == n)
                break;

            attackleft -= minPowerRight[it];
        }
        if (attackleft > 0)
            cout << "YES";
        else
            cout << "NO";

        cout << endl;
    }
}