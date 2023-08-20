#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

bool cmp(pair<pair<int, ll>, int> x, pair<pair<int, ll>, int> y)
{
    if (x.first.first != y.first.first)
        return x.first.first > y.first.first;

    if (x.first.second != y.first.second)
        return x.first.second < y.first.second;

    return x.second < y.second;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        ll h;
        cin >> n >> m >> h;
        vector<pair<pair<int, ll>, int>> v;

        for (int i = 0; i < n; i++)
        {
            int a[m];
            int j;
            for (j = 0; j < m; j++)
            {
                cin >> a[j];
            }

            sort(a, a + m);

            ll duration[m];
            duration[0] = a[0];

            for (j = 1; j < m; j++)
            {
                duration[j] = duration[j - 1] + a[j];
            }

            j = 0;
            ll penalty = 0;
            while (duration[j] <= h && j < m)
            {
                penalty += duration[j];
                j++;
            }

            v.push_back(make_pair(make_pair(j, penalty), i));
        }

        sort(v.begin(), v.end(), cmp);

        for (int i = 0; i < n; i++)
        {
            if (v[i].second == 0)
            {
                cout << (i + 1);
                break;
            }
        }

        // for (auto it : v)
        // {
        //     cout << it.first.first << " " << it.first.second << " " << it.second << endl;
        // }
        
        cout << endl;
    }
}