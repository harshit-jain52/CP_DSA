#include <bits/stdc++.h>
using namespace std;

int main()
{
    char s[1001];
    int i;

    gets(s);
    if (s[0] >= 'a' && s[0] <= 'z')
    {
        s[0] = s[0] - ('a' - 'A');
    }

    puts(s);

    return 0;
}