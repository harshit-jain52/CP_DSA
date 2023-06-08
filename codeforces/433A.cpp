#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, flag = 0, temp, count100 = 0, count200 = 0;
    cin >> n;

    for (i = 0; i < n; i++)
    {
        cin >> temp;
        if (temp == 100)
            count100++;
        else
            count200++;
    }

    if (count100 % 2 == 0)
    {
        if (count200 % 2 == 0)
        {
            flag = 1;
        }
        else if (count100 >= 2)
        {
            flag = 1;
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
