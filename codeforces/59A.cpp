#include <bits/stdc++.h>
using namespace std;

int main()
{
    char s[101];
    gets(s);

    int lwr = 0, upr = 0, i;

    for (i = 0; s[i] != '\0'; i++)
    {
        switch (s[i])
        {
        case 'a' ... 'z':
            lwr++;
            break;
        case 'A' ... 'Z':
            upr++;
            break;
        }
    }

    if (upr > lwr)
    {
        cout << strupr(s);
    }
    else
    {
        cout << strlwr(s);
    }

    return 0;
}