#include <bits/stdc++.h>
using namespace std;
typedef long long lli;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i;
    cin >> n >> m;
    lli a[n + 1], ysum = 0;
    vector<lli> ynullify(n + 1, 0);

    for (i = 1; i < n + 1; i++)
    {
        cin >> a[i];
    }

    while (m--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int v;
            lli x;
            cin >> v >> x;
            a[v] = x;
            ynullify[v] = -ysum;
        }
        else if (t == 2)
        {
            lli y;
            cin >> y;
            ysum += y;
        }
        else
        {
            int q;
            cin >> q;
            cout << a[q] + ysum + ynullify[q] << '\n';
        }
    }
}