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
        ll h[n], diff[n];

        for (i = 0; i < n; i++)
        {
            cin >> h[i];
        }

        sort(h, h + n);

        ll mindiff = 1e9;
        int idx;
        for (i = 1; i < n; i++)
        {
            diff[i] = h[i] - h[i - 1];
            if (diff[i] < mindiff)
            {
                mindiff = diff[i];
                idx = i;
            }
        }

        cout << h[idx - 1] << " ";
        for (i = idx + 1; i < n; i++)
        {
            cout << h[i] << " ";
        }
        for (i = 0; i < idx - 1; i++)
        {
            cout << h[i] << " ";
        }
        cout << h[idx] << " ";

        cout << endl;
    }
}