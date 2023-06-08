/*
https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/monk-and-his-friends/
*/

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
        int n, m, i;
        cin >> n >> m;
        ll temp;
        unordered_set<ll> s;

        for (i = 0; i < n; i++)
        {
            cin >> temp;
            s.insert(temp);
        }

        for (i = 0; i < m; i++)
        {
            cin >> temp;
            if (s.find(temp) != s.end())
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
                s.insert(temp);
            }
        }
    }
}