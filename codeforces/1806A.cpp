#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, c, d, ydiff;
        cin >> a >> b >> c >> d;

        if (d < b)
        {
            cout << -1;
        }
        else
        {
            ydiff = d - b;
            if (a + ydiff < c)
            {
                cout << -1;
            }
            else
            {
                cout << ydiff + (a + ydiff) - c;
            }
        }
        cout << endl;
    }
}