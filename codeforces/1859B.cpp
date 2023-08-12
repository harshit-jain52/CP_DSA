#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll sum = 0, min1 = 1e9+2, min2 = 1e9+2;
        int n;
        cin >> n;

        while (n--)
        {
            int m;
            cin >> m;

            ll a[m];
            for (int i = 0; i < m; i++)
            {
                cin >> a[i];
            }

            sort(a, a + m);
            min1 = min(min1, a[0]);
            min2 = min(min2, a[1]);
            sum += a[1];
        }

        sum += min1;
        sum -= min2;

        cout << sum << endl;
    }
}