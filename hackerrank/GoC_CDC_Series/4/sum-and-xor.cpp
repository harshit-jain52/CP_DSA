#include <bits/stdc++.h>
using namespace std;

// A+B = A^B + 2*(A&B)

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int s, x;
        cin >> s >> x;
        if (s < x || ((s - x) & 1))
        {
            cout << -1 << " " << -1 << endl;
            continue;
        }

        if (s == x)
        {
            cout << 0 << " " << s << endl;
            continue;
        }

        int diff = s - x;
        int an = diff / 2; // A&B
        if (an & x)
        {
            cout << -1 << " " << -1 << endl;
            continue;
        }

        cout << an << " " << (s - an) << endl;
    }
}