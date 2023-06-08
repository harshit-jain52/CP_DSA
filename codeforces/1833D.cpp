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
        int n, i, idx1, idx2 = -1;
        cin >> n;
        int p[n];

        for (i = 0; i < n; i++)
        {
            cin >> p[i];
            if (p[i] == n)
            {
                idx1 = i;
            }
        }

        if (n == 1)
        {
            cout << 1;
        }
        else
        {
            if (idx1 == 0)
            {
                for (i = 0; i < n; i++)
                {
                    if (p[i] == n - 1)
                    {
                        idx1 = i;
                    }
                }
            }

            for (i = idx1; i < n; i++)
            {
                cout << p[i] << " ";
            }

            if (idx1 != n - 1)
            {
                cout << p[idx1 - 1] << " ";
                idx1--;
            }

            for (i = idx1 - 1; i >= 0; i--)
            {
                if (p[i] > p[0])
                {
                    cout << p[i] << " ";
                }
                else
                {
                    idx2 = i;
                    break;
                }
            }

            for (i = 0; i <= idx2; i++)
            {
                cout << p[i] << " ";
            }
        }
        cout << endl;
    }
}