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
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;

        int p[m], i, j;
        vector<int> posi(n + 1, 0);

        for (i = 0; i < m; i++)
        {
            cin >> p[i];
            posi[p[i]]++;
        }

        vector<ll> ct(n + 1, 0);
        ct[n] = 1;
        for (i = n - 1; i >= 1; i--)
        {
            ct[i] = ct[i + 1] + posi[i];
        }

        vector<ll> ans(26, 0);

        for (i = 0; i < n; i++)
        {
            ans[s[i] - 'a'] += ct[i + 1];
        }

        for (auto it : ans)
        {
            cout << it << " ";
        }
        cout << endl;
    }
}