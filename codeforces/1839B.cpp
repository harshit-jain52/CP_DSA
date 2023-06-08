#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp(pair<int, ll> x, pair<int, ll> y)
{
    if (x.first != y.first)
        return x.first < y.first;

    else
    {
        if (x.second != y.second)
            return x.second > y.second;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, ll>> ab;

        for (int i = 0; i < n; i++)
        {
            int a;
            ll b;
            cin >> a >> b;
            ab.push_back({a, b});
        }

        sort(ab.begin(), ab.end(), cmp);

        // for (auto it : ab)
        // {
        //     cout << it.first << " " << it.second << endl;
        // }
        // cout << endl;

        int curr = 1, ct = 0;
        ll tot = 0;
        for (auto it : ab)
        {
            int a = it.first;
            ll b = it.second;

            if (a == curr && ct < curr)
            {
                tot += b;
                ct++;
            }
            else if (a != curr)
            {
                ct = 1;
                curr = a;
                tot += b;
            }
        }

        cout << tot << endl;
    }
}