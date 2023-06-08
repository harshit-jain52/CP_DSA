#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, count0 = 0, count5 = 0;
    char ch;
    string s = "";

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> ch;

        switch (ch)
        {
        case '5':
            count5++;
            break;

        case '0':
            count0++;
            break;
        }
    }
    cout << s;
    if (count0 == 0)
    {
        cout << -1;
    }
    else if (count5 < 9)
    {
        cout << 0;
    }
    else
    {
        for (i = 0; i < (count5 - count5 % 9); i++)
        {
            s.push_back('5');
        }

        for (int i = 0; i < count0; i++)
        {
            s.push_back('0');
        }

        cout << s;
    }
}