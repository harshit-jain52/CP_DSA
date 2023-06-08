#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, i, j, k, x;
    cin >> n;

    m = n * n;
    x = 2 * n;

    for (i = 0; i < n; i++)
    {
        k = i + 1;
        cout << k << " ";
        for (j = 1; j < n; j++)
        {

            if (j % 2 == 0)
            {
                k += 2 * i + 1;
            }
            else
            {
                k += x - (2 * i + 1);
            }
            cout << k << " ";
        }
        cout << endl;
    }
}