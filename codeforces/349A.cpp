#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, n, count25 = 0, count50 = 0, count100 = 0;

    cin >> n;

    int bills[n];

    for (i = 0; i < n; i++)
    {
        cin >> bills[i];
    }

    for (i = 0; i < n; i++)
    {
        if (bills[i] == 25)
        {
            count25++;
        }
        else if (bills[i] == 50)
        {
            if (count25 == 0)
            {
                break;
            }
            count25--;
            count50++;
        }
        else
        {
            if (count50 > 0 && count25 > 0)
            {
                count25--;
                count50--;
                count100++;
            }
            else if (count50 == 0 && count25 >= 3)
            {
                count25 = count25 - 3;
                count100++;
            }
            else{
                break;
            }
        }
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