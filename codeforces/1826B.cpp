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
        int n, i;
        cin >> n;
        ll a[n], g = 0;

        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (i = 0; i < n / 2; i++)
        {
            g = __gcd(g, abs(a[i] - a[n - 1 - i]));
        }

        cout << g << endl;
    }
}