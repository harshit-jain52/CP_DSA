#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, evensum = 0, oddsum = 0, temp, i;
        cin >> n;

        for (i = 0; i < n; i++)
        {
            cin >> temp;
            if (temp % 2 == 0)
            {
                evensum += temp;
            }
            else
            {
                oddsum += temp;
            }
        }

        if (evensum > oddsum)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
        cout << endl;
    }
}