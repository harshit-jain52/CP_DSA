#include <bits/stdc++.h>
using namespace std;

bool isPresent(int arr[], int size, int key)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int n, i, arr[100];
    long long ways, count0;

    cin >> n;

    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (isPresent(arr, n, 1))
    {
        ways = 1;
        i = 0;
        while (i < n)
        {
            if (arr[i] == 1)
            {
                i++;
                count0 = 0;
                while (arr[i] != 1 && i < n)
                {
                    count0++;
                    i++;
                }

                if (i == n)
                {
                    break;
                }
                else
                {
                    ways *= (count0 + 1);
                }
            }
            else
            {
                i++;
            }
        }
    }

    else
    {
        ways = 0;
    }

    cout << ways;
    return 0;
}