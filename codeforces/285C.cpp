#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
int main()
{
    lli n, i, count = 0;
    cin >> n;
    lli a[n];

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    for (i = 0; i < n; i++)
    {
        count += abs(a[i] - (i + 1));
    }

    cout << count;
}