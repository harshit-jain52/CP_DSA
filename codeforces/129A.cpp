#include <bits/stdc++.h>
using namespace std;

int main()
{
    int temp, i, n, odd = 0, even = 0, sum = 0;
    cin >> n;

    for (i = 0; i < n; i++)
    {
        cin >> temp;
        sum += temp;
        if (temp % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }

    if (sum % 2 == 0)
    {
        cout << even;
    }
    else
    {
        cout << odd;
    }
}