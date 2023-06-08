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
        ll n, m;
        cin >> n >> m;
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        vector<pair<ll, ll>> v;
        v.push_back({1, 1});
        v.push_back({1, m});
        v.push_back({n, m});
        v.push_back({n, 1});

        if (find(v.begin(), v.end(), make_pair(x1, y1)) != v.end())
        {
            cout << 2 << endl;
            continue;
        }

        if (find(v.begin(), v.end(), make_pair(x2, y2)) != v.end())
        {
            cout << 2 << endl;
            continue;
        }

        if (x1 == 1 || x1 == n || x2 == 1 || x2 == n)
        {
            cout << 3 << endl;
            continue;
        }

        if (y1 == 1 || y1 == m || y2 == 1 || y2 == m)
        {
            cout << 3 << endl;
            continue;
        }

        cout << 4 << endl;
    }
}