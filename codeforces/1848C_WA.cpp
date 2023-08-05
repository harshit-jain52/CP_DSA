#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], b[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        int ct[n];

        for (int i = 0; i < n; i++)
        {
            int x = a[i], y = b[i];
            int count = 0;

            while (x != 0)
            {
                int z = abs(y - x);
                x = y;
                y = z;
                count++;
            }

            ct[i] = count;
        }

        bool ans = true;

        for (int i = 1; i < n; i++)
        {
            if ((a[i] == 0 && b[i] == 0) || (a[i - 1] == 0 && b[i - 1] == 0))
                continue;
            if (ct[i] % 3 != ct[i - 1] % 3)
            {
                ans = false;
                break;
            }
        }

        if (ans)
            cout << "YES";
        else
            cout << "NO";

        cout << endl;
    }
}