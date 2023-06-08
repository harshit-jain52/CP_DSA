#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b = "";
    int count0 = 0, i;
    cin >> a;

    for (i = 0; i < a.length(); i++)
    {
        if (a[i] == '0')
        {
            count0++;
            if (count0 == 1)
            {
                continue;
            }
        }

        if (count0 == 0 && i == a.length() - 1)
        {
            continue;
        }

        b.push_back(a[i]);
    }

    cout << b;
}