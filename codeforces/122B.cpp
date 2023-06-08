#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int count4 = 0, count7 = 0;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '4')
        {
            count4++;
        }
        else if (s[i] == '7')
        {
            count7++;
        }
    }

    if (count4 == 0 && count7 == 0)
    {
        cout << -1;
    }
    else if (count7 > count4)
    {
        cout << 7;
    }
    else
    {
        cout << 4;
    }
}