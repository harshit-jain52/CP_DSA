#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (a + b == c)
        {
            cout << "+";
        }
        else
        {
            cout << "-";
        }
        cout << endl;
    }
}