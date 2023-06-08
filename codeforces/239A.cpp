#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long y, k, n, i, count = 0;

    cin >> y >> k >> n;

    for (i = k - y % k; i <= n - y; i += k)
    {
        cout << i << " ";
        count++;
    }
    if (count == 0)
    {
        cout << -1;
    }
}