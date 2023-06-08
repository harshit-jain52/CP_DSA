#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, l, r, i, min = 1000, diff;
    cin >> n;
    int arr[n + 1];

    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    arr[n] = arr[0];

    for (i = 0; i < n; i++)
    {
        diff = abs(arr[i] - arr[i + 1]);
        if (diff < min)
        {
            l = i;
            r = i + 1;
            min = diff;
        }
    }

    if (r == n)
    {
        r = 0;
    }

    cout << l + 1 << " " << r + 1;
}