#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x = 0, i;
    string statement;

    cin >> n;

    for (i = 0; i < n; i++)
    {
        cin >> statement;

        if (statement == "X++" || statement == "++X")
        {
            x++;
        }
        else
        {
            x--;
        }
    }

    cout << x;

    return 0;
}