#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, count = 0;
    cin >> n;

    if (n % 2 == 0)
    {
        count = n / 4 - (int)(n % 4 == 0);
    }

    cout << count;
}