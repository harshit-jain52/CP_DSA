#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, x, i, f;

    cin >> t;

    while (t--)
    {
        cin >> n >> x;

        for (f = 1, i = 2;; f++)
        {
            if (n <= i)
            {
                break;
            }

            i += x;
        }

        cout << f << endl;
        ;
    }
}