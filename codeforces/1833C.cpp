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
        int n;
        cin >> n;
        bool ev = false, od = false;
        ll a[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] % 2 == 0)
            {
                ev = true;
            }
            else
            {
                od = true;
            }
        }

        sort(a, a + n);
        bool ans;
        if (a[0] % 2 != 0)
        {
            ans = true;
        }
        else
        {
            if (ev && od)
            {
                ans = false;
            }
            else
            {
                ans = true;
            }
        }

        if (ans)
            cout << "YES";
        else
            cout << "NO";

        cout << endl;
    }
}