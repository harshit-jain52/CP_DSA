#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i;
    cin >> n >> m;
    vector<set<char>> v(m);

    while (n--)
    {
        string s;
        cin >> s;
        for (i = 0; i < m; i++)
        {
            v[i].insert(s[i]);
        }
    }

    ll total = 1;
    for (i = 0; i < m; i++)
    {
        total = (total * (v[i].size() % M)) % M; // (a*b)%M = ((a%M)*(b%M))%M
    }

    cout << total;
}