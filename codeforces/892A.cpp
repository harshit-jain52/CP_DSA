#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, flag = 0;
    long long temp, sum = 0, max1 = 0, max2 = 0;

    cin >> n;

    for (i = 0; i < n; i++)
    {
        cin >> temp;
        sum += temp;
    }

    for (i = 0; i < n; i++)
    {
        cin >> temp;
        if (flag == 0)
        {
            if (temp > max1)
            {
                max2 = max1;
                max1 = temp;
            }
            else if (temp > max2)
            {
                max2 = temp;
            }

            if (max1 + max2 >= sum)
            {
                flag = 1;
            }
        }
    }

    if (flag)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}