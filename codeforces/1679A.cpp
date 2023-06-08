#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    long long n, rem, max, min;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n < 4 || n % 2 == 1)
        {
            cout << -1;
        }
        else
        {
            max = n / 4;

            min = n / 6;
            if (n % 6 != 0)
            {
                min++;
            }

            cout << min << " " << max;
        }

        cout << endl;
    }
}