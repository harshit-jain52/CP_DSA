#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int i, n, temp, count0 = 0, ifexcept1 = 0;
        cin >> n;

        for (i = 0; i < n; i++)
        {
            cin >> temp;
            if (temp == 0)
            {
                count0++;
            }
            else if (temp != 1)
            {
                ifexcept1 = 1;
            }
        }

        if (count0 == n)
        {
            cout << 1;
        }
        else
        {
            if (count0 > (n + 1) / 2)
            {
                if (ifexcept1)
                    cout << 1;
                else
                {
                    cout << 2;
                }
            }
            else
            {
                cout << 0;
            }
        }
        cout << endl;
    }
}