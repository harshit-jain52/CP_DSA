#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, a, b;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        a = abs(a);
        b = abs(b);

        int moves = (a + b) + abs(a - b);
        if (abs(a - b))
        {
            moves--;
        }
        cout << moves << endl;
    }
}