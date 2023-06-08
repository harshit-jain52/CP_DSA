#include <bits/stdc++.h>
using namespace std;

typedef long int li;

bool isPresent(li arr[4], li key)
{
    int i;
    for (i = 0; i < 4; i++)
    {
        if (key == arr[i])
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    li arr[4], distinct[4] = {0, 0, 0, 0};
    int i, count = 0;

    for (i = 0; i < 4; i++)
    {
        cin >> arr[i];
        if (isPresent(distinct, arr[i]))
        {
            count++;
        }
        else
        {
            distinct[i] = arr[i];
        }
    }

    cout << count;

    return 0;
}