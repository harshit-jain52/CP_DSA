#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int lo = 0, hi = n - 1;
    int ct = 0;
    while (lo < hi)
    {
        while (lo < hi && a[lo] % 2 == 0)
            lo++;
        while (hi > lo && a[hi] % 2 == 1)
            hi--;
        if (lo >= hi)
            break;
        swap(a[lo], a[hi]);
        ct++;
        lo++;
        hi--;
    }
    cout << ct;
}