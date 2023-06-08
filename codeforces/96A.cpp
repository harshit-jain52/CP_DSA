#include <bits/stdc++.h>
using namespace std;

int main()
{
    string positions;
    int count1 = 0, count0 = 0, i, n;
    cin >> positions;
    n = positions.size();

    for (i = 0; i < n; i++)
    {
        if (count1 > 0 && positions[i] == '0')
        {
            count1 = 0;
            count0 = 1;
        }
        else if (count0 > 0 && positions[i] == '1')
        {
            count0 = 0;
            count1 = 1;
        }
        else if (positions[i] == '0')
        {
            count0++;
        }
        else
        {
            count1++;
        }

        if (count1 >= 7 || count0 >= 7)
        {
            break;
        }
    }

    if (i == n)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES";
    }
}