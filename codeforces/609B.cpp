#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, j;
    cin >> n >> m;
    int temp;
    vector<ll> g(m + 1, 0);

    for (i = 0; i < n; i++)
    {
        cin >> temp;
        g[temp]++;
    }

    ll ans = 0;

    for (i = 1; i < m; i++)
    {
        for (j = i + 1; j <= m; j++)
        {
            ans += g[i] * g[j];
        }
    }

    cout << ans;
}