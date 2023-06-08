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
        ll bsum = 0;
        vector<ll> b(n + 2);

        for (i = 0; i < n + 2; i++)
        {
            cin >> b[i];
        }

        sort(b.begin(), b.end());

        for (i = 0; i < n + 1; i++)
        {
            bsum += b[i];
        }
        int idx;

        for (idx = 0; idx < n + 1; idx++)
        {
            if (b[idx] == bsum - b[n + 1])
            {
                break;
            }
        }

        if (idx == n + 1)
        {
            if (bsum == 2 * b[n])
            {
                for (i = 0; i < n; i++)
                {
                    cout << b[i] << " ";
                }
            }
            else
            {
                cout << -1;
            }
        }
        else
        {
            for (i = 0; i < n + 1; i++)
            {
                if (i == idx)
                {
                    continue;
                }
                cout << b[i] << " ";
            }
        }
        cout << endl;
    }
}