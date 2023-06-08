#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, a, b, c, d;

    /*
    4 cases:
    a b | d a | c d | b c
    d c | c b | b a | a d
    */
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> d >> c;

        if ((a - b) * (d - c) > 0 && (a - d) * (b - c) > 0)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
        cout << endl;
    }
}