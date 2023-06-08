#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, ct = 0;
    cin >> n;
    int i, arr[] = {100, 20, 10, 5, 1};

    for (i = 0; i < 5; i++)
    {
        ct += n / arr[i];
        n = n % arr[i];
    }

    cout << ct;
}