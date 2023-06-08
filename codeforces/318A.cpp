#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main()
{
    lli n, k, oddnums;

    cin >> n >> k;

    oddnums = n / 2 + n % 2;

    if (k <= oddnums)
    {
        cout << (2 * k - 1);
    }
    else
    {
        cout << 2 * (k - oddnums);
    }

    return 0;
}