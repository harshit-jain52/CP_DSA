#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> s;
        cout << (int)(s[0] - '0') + (int)(s[2] - '0') << endl;
    }
}