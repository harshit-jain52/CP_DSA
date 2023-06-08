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
        ll c[n];

        for (i = 0; i < n; i++)
        {
            cin >> c[i];
        }
        sort(c, c + n);

        if (c[0] != 1)
        {
            cout << "NO";
        }
        else
        {
            // starting array a with number 1 ensures that at a point, we can get every number <= sum at that point

            ll csum = 1;
            for (i = 1; i < n; i++)
            {
                if (csum < c[i])
                {
                    break;
                }
                csum += c[i];
            }

            if (i == n)
            {
                cout << "YES";
            }
            else
            {
                cout << "NO";
            }
        }
        cout << endl;
    }
}