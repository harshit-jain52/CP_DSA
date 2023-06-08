#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, count, temp, sum;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            sum += temp;
        }

        count = 0;

        if (sum < n)
        {
            count++;
        }

        else
        {
            while (sum != n)
            {
                n++;
                count++;
            }
        }

        cout << count;
        cout << "\n";
    }

    return 0;
}