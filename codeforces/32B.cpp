#include <bits/stdc++.h>
using namespace std;

int main()
{
    string code;
    int i;

    cin >> code;

    for (i = 0; code[i] != '\0'; i++)
    {
        if (code[i] == '-')
        {
            if (code[i + 1] == '.')
            {
                cout << 1;
            }
            else
            {
                cout << 2;
            }
            i++;
        }
        else
        {
            cout << 0;
        }
    }

    return 0;
}