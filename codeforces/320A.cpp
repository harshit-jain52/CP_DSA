#include <bits/stdc++.h>
using namespace std;

int main()
{
    string n;
    int i;
    bool con1, con2, con3;

    cin >> n;
    n = "  " + n;

    for (i = 2; n[i] != '\0'; i++)
    {
        con1 = n[i] != '1' && n[i] != '4';
        con2 = n[i] == '4' && n[i - 1] != '1' && n[i - 1] != '4';
        con3 = n[i] == '4' && n[i - 1] == '4' && n[i - 2] != '1';

        if (con1 || con2 || con3)
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}