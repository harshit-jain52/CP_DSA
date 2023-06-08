#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, j, back = 0;
    cin >> n;

    for (i = 0; i >= 0;)
    {
        for (j = 0; j < n - i; j++)
        {
            cout << " "
                 << " ";
        }

        for (j = 0; j < i; j++)
        {
            cout << j << " ";
        }
        cout << j;

        for (j = i - 1; j >= 0; j--)
        {
            cout << " " << j;
        }

        cout << endl;

        if (i == n)
            back = 1;

        if (back)
            i--;
        else
            i++;
    }
}