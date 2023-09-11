#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        ll y;
        cin >> n >> m >> y;

        ll a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a, a + n);

        ll b[m - 1];
        ll k = 0;

        for (int i = 0; i < m - 1; i++)
        {
            cin >> b[i];

            k += (int)(upper_bound(a, a + n, b[i]) - a);
        }

        if (k >= y)
            cout << 0;

        else if (y - k > n)
            cout << -1;

        else
            cout << a[y - k - 1];

        cout << endl;
    }
}