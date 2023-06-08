#include <bits/stdc++.h>
using namespace std;

int main()
{
    char p[101];
    gets(p);
    int i;

    for (i = 0; p[i] != '\0'; i++)
    {
        if (p[i] == 'H' || p[i] == 'Q' || p[i] == '9')
        {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;
}