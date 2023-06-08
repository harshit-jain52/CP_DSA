#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        int b[n], i, pos = 0, neg = 0;

        for (i = 0; i < n; i++)
        {
            cin >> b[i];
            if (b[i] > 0)
            {
                pos++;
            }
            else
            {
                neg++;
            }
        }

        // maximum

        for (i = 1; i <= pos; i++)
        {
            cout << i << " ";
        }
        for (int j = 0, i = pos - 1; j < neg; i--, j++)
        {
            cout << i << " ";
        }
        cout << endl;

        // minimum
        for (i = 0; i < neg; i++)
        {
            cout << 1 << " " << 0 << " ";
        }
        for (i = 1; i <= pos - neg; i++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}