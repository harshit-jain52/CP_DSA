#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, a = 0, d = 0;
    char ch;
    cin >> n;

    for (i = 0; i < n; i++)
    {
        cin >> ch;

        if (ch == 'A')
            a++;
        else
            d++;
    }

    if (a > d)
    {
        cout << "Anton";
    }
    else if (d > a)
    {
        cout << "Danik";
    }
    else
    {
        cout << "Friendship";
    }
}