#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x)
{
    int i;
    if (x == 2)
    {
        return 1;
    }

    for (i = 2; i <= x / 2; i++)
    {
        if (x % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n, m, i;

    cin >> n >> m;

    for (i = n + 1;; i++)
    {
        if (isPrime(i))
        {
            break;
        }
    }

    if (m == i)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}