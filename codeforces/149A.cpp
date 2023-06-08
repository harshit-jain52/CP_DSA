#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k, a[12], i, sum = 0;
    cin >> k;

    for (i = 0; i < 12; i++)
    {
        cin >> a[i];
    }

    sort(a, a + 12, greater<int>());

    i = 0;
    while (sum < k && i < 12)
    {
        sum += a[i];
        i++;
    }

    if (sum >= k)
    {
        cout << i;
    }
    else
    {
        cout << -1;
    }
}