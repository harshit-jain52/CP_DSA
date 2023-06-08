#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int c[n], i;

        for (i = 0; i < n; i++)
        {
            cin >> c[i];
        }
        sort(c, c + n);

        if (c[0] != 1)
        {
            cout << "NO";
        }
        else
        {
            // starting array a with number 1 ensures that at a point, we can get every number <= sum at that point

            int csum = 1;
            for (i = 1; i < n; i++)
            {
                if (csum < c[i])
                {
                    break;
                }
                csum += c[i];
            }

            if (i == n)
            {
                cout << "YES";
            }
            else
            {
                cout << "NO";
            }
        }
        cout << endl;
    }
}