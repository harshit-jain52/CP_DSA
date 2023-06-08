#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, sum = 0, temp, i;
    cin >> n >> x;

    for (i = 0; i < n; i++)
    {
        cin >> temp;
        sum += temp;
    }
    sum = abs(sum);
    cout << sum / x + (int)(sum % x != 0);
}