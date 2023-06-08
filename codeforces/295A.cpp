#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k, i;
    cin >> n >> m >> k;
    ll a[n + 1];

    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int l[m + 1], r[m + 1];
    ll d[m + 1];

    for (i = 1; i <= m; i++)
    {
        cin >> l[i] >> r[i] >> d[i];
    }

    vector<int> v(m + 2, 0);
    int x, y;
    for (i = 0; i < k; i++)
    {
        cin >> x >> y;
        v[x]++;
        v[y + 1]--;
    }

    ll vsum[m + 1];
    vsum[0] = 0;
    for (i = 1; i <= m; i++)
    {
        vsum[i] = vsum[i - 1] + v[i];
    }

    vector<ll> ops(n + 2, 0);
    for (i = 1; i <= m; i++)
    {
        ops[l[i]] += vsum[i] * d[i];
        ops[r[i] + 1] -= vsum[i] * d[i];
    }
    ll osum[n + 1];
    osum[0] = 0;
    for (i = 1; i <= n; i++)
    {
        osum[i] = osum[i - 1] + ops[i];
    }

    for (i = 1; i <= n; i++)
    {
        cout << a[i] + osum[i] << " ";
    }
}