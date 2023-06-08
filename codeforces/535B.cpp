#include <bits/stdc++.h>
using namespace std;

int main()
{
    int b = 1, i;
    string s;
    cin >> s;
    for (i = 0; i < s.size(); i++)
    {
        if (s[i] == '4')
        {
            b <<= 1;
        }
        else
        {
            b <<= 1;
            b += 1;
        }
    }
    cout << (b - 1);
}