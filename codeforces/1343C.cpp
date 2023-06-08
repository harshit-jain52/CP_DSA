#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 1;

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

        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        bool pos = false;
        ll maxpos = 0, maxneg = -INF;

        ll sum = 0;

        for (i = 0; i < n; i++)
        {
            if (a[i] > 0)
            {
                pos = true;
                sum += ((maxneg == -INF) ? 0 : maxneg);
                maxneg = -INF;
            }
            else
            {
                pos = false;
                sum += maxpos;
                maxpos = 0;
            }

            if (pos)
            {
                maxpos = max(maxpos, a[i]);
            }
            else
            {
                maxneg = max(maxneg, a[i]);
            }
        }
        sum += maxpos + ((maxneg == -INF) ? 0 : maxneg);

        cout << sum << endl;
    }
}