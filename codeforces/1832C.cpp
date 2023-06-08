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
        int n, ans, i;
        cin >> n;
        ans = n;

        ll a[n], left;

        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        left = a[0];
        for (i = 1; i < n - 1; i++)
        {
            bool con1 = ((left <= a[i]) && (a[i] <= a[i + 1]));
            bool con2 = ((left >= a[i]) && (a[i] >= a[i + 1]));

            if (con1 || con2)
                ans--;
            else
                left = a[i];
        }

        if (ans == 2)
        {
            if (left == a[n - 1])
                ans--;
        }

        cout << ans << endl;
    }
}