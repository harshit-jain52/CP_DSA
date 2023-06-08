#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, ltemp, rtemp, lcount1 = 0, rcount1 = 0, i;

    cin >> n;

    for (i = 0; i < n; i++)
    {
        cin >> ltemp >> rtemp;
        lcount1 += ltemp;
        rcount1 += rtemp;
    }

    cout << (min(n - lcount1, lcount1) + min(n - rcount1, rcount1));

    return 0;
}