#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n], i;
    long long sum = 0;

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    if (sum % n == 0)
    {
        cout << n;
    }
    else
    {
        cout << n - 1;
    }
}