#include <bits/stdc++.h>
using namespace std;

bool isBeautiful(int a)
{
    int arr[4], i = 0, j;

    while (a != 0)
    {
        arr[i] = a % 10;
        a /= 10;
        i++;
    }

    for (i = 0; i < 3; i++)
    {
        for (j = i + 1; j < 4; j++)
        {
            if (arr[i] == arr[j])
            {
                return 0;
            }
        }
    }

    return 1;
}

int main()
{
    int y, z;
    cin >> y;

    for (z = y + 1;; z++)
    {
        if (isBeautiful(z))
        {
            break;
        }
    }

    cout << z;

    return 0;
}