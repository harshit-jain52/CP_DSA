#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, sum = 0, i, temp, count = 0;
    cin >> n;

    for (i = 0; i < n; i++)
    {
        cin >> temp;
        sum += temp;
    }

    for (i = 1; i <= 5; i++)
    {
        if ((i + sum) % (n + 1) != 1)
        {
            count++;
        }
    }

    cout << count;
}