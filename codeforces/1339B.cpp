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
        int n, i, j;
        cin >> n;
        ll a[n];

        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a, a + n);

        vector<ll> v;

        for (i = 0, j = n - 1; i <= j; i++, j--)
        {
            if (i == j)
            {
                v.push_back(a[i]);
            }
            else
            {
                v.push_back(a[j]);
                v.push_back(a[i]);
            }
        }

        for (i = n - 1; i >= 0; i--)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
}