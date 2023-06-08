#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;

    cin >> t;
    while (t--)
    {
        cin >> n;
        int b[n], i, temp1 = 0, occupied = 0, aviaries = 0, totalM = 0;

        for (i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        for (i = 0; i < n; i++)
        { // F
            if (b[i] == 1)
            {
                occupied++;
                aviaries++;
                i++;
                break;
            }
        }

        for (; i < n; i++)
        {
            if (b[i] == 1)
            {
                temp1++;
                totalM++;
                if (aviaries == occupied)
                {
                    aviaries++;
                }
                occupied++;
            }
            if (b[i] == 2)
            {
                occupied -= temp1;
                occupied = 1 + (totalM / 2 + totalM % 2);
                if (occupied > aviaries)
                {
                    aviaries = occupied;
                }
                temp1 = 0;
            }
        }

        cout << aviaries << endl;
    }
}