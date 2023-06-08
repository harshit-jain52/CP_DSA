#include <bits/stdc++.h>
using namespace std;

int main()
{
    char guest[101], host[101], gh[201], pile[101];
    gets(guest);
    gets(host);
    gets(pile);

    strcpy(gh, strcat(guest, host));

    sort(gh, gh + strlen(gh));
    sort(pile, pile + strlen(pile));

    if (strcmp(pile, gh) == 0)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}