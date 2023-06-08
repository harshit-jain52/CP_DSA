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
        int a[n + 1];
        for (i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        if (a[1] == 1)
        {
            cout << n + 1 << " ";
            for (i = 1; i <= n; i++)
            {
                cout << i << " ";
            }
        }
        else if (a[n] == 0)
        {
            for (i = 1; i <= n + 1; i++)
            {
                cout << i << " ";
            }
        }
        else
        {
            bool flag = false;
            int idx;
            for (i = 1; i < n; i++)
            {
                if (a[i] == 0 && a[i + 1] == 1)
                {
                    flag = true;
                    idx = i;
                    false;
                }
            }

            if (flag)
            {
                for (i = 1; i <= idx; i++)
                {
                    cout << i << " ";
                }
                cout << n + 1 << " ";
                for (i = idx + 1; i <= n; i++)
                {
                    cout << i << " ";
                }
            }
            else
            {
                cout << -1;
            }
        }
        cout << endl;
    }
}