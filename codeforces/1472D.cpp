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
        ll a[n], alice = 0, bob = 0;
        bool flag = 1;
        // flag = 1 -- alice's turn
        // flag = 0 -- bob's turn

        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);

        for (i = n - 1; i >= 0; i--)
        {
            if (flag)
            {
                if (a[i] % 2 == 0)
                {
                    alice += a[i];
                }
            }
            else
            {
                if (a[i] % 2)
                {
                    bob += a[i];
                }
            }

            flag = (flag) ? 0 : 1; // 0<-->1
        }

        if (alice > bob)
        {
            cout << "Alice";
        }
        else if (bob > alice)
        {
            cout << "Bob";
        }
        else
        {
            cout << "Tie";
        }
        // cout << alice << " " << bob;
        cout << endl;
    }
}