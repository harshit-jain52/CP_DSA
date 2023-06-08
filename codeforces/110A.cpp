#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

bool isLucky(lli n)
{
    if (n < 4)
    {
        return 0;
    }

    int dig;
    while (n > 0)
    {
        dig = n % 10;

        if (dig != 4 && dig != 7)
        {
            return 0;
        }

        n /= 10;
    }

    return 1;
}

int main()
{
    lli n;
    cin >> n;

    lli temp = n, lucky = 0;
    int dig;

    while (temp != 0)
    {
        dig = temp % 10;

        if (dig == 4 || dig == 7)
        {
            lucky++;
        }

        temp /= 10;
    }

    if (isLucky(lucky))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}