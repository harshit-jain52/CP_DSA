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
        int n, q;
        cin >> n >> q;

        vector<ll> statues(n + 2, 0);
        vector<pair<int, int>> queries;
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            queries.push_back({l, r});
        }

        for (auto qry : queries)
        {
            int l = qry.first, r = qry.second;
            statues[l]++;
            statues[r + 1]--;
        }

        for (int i = 1; i <= n; i++)
            statues[i] += statues[i - 1];

        for (auto qry : queries)
        {
            int l = qry.first, r = qry.second;
            statues[r + 1] -= r - l + 1;
        }

        for (int i = 1; i <= n; i++)
            statues[i] += statues[i - 1];

        for (int i = 1; i <= n; i++)
            cout << statues[i] << " ";
    }
}