#include <bits/stdc++.h>
using namespace std;

int main()
{
    char s1[101], s2[101];
    int res;

    gets(s1);
    gets(s2);

    res = strcmpi(s1, s2);

    if (res < 0)
    {
        cout << -1;
    }
    else if (res > 0)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }

    return 0;
}