#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// void printVec(vector<ll> &v)
// {
//     for (auto it : v)
//     {
//         cout << it << " ";
//     }
//     cout << endl;
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;

        ll a[n];
        map<ll, int> m;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            m[a[i]]++;
        }
        map<int, int> c;

        for (auto it : m)
        {
            c[it.second]++;
        }
        m.clear();

        vector<ll> v;
        for (auto it : c)
        {
            v.push_back(it.first);
        }
        int x = v.size();
        vector<ll> sumleft(x + 1, 0), sumright(x + 1, 0), ctright(x + 1, 0);

        for (i = 0; i < x; i++)
        {
            sumleft[i + 1] = sumleft[i] + c[v[i]] * v[i];
        }

        for (i = 0; i < x; i++)
        {
            sumright[i + 1] = sumright[i] + c[v[x - 1 - i]] * v[x - 1 - i];
        }

        for (i = 0; i < x; i++)
        {
            ctright[i + 1] = ctright[i] + c[v[x - 1 - i]];
        }

        ll ans = INT_MAX;

        for (i = 0; i < x; i++)
        {
            ans = min(ans, sumleft[i] + sumright[x - i] - v[i] * ctright[x - i]);
        }

        cout << ans << endl;

        // printVec(v);
        // printVec(sumleft);
        // printVec(sumright);
        // printVec(ctright);
    }
}