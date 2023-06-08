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
        ll n, a, b;
        cin >> n >> a >> b;
        bool flag = false;

        if (a == 1)
        {
            if ((n - 1) % b == 0)
            {
                flag = true;
            }
        }
        else
        {
            ll x = 1;
            while (x <= n)
            {
                if ((n - x) % b == 0)
                {
                    flag = true;
                    break;
                }
                x *= a;
            }
        }

        if (flag)
            cout << "Yes";
        else
            cout << "No";

        cout << endl;
    }
}