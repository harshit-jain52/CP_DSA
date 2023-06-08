#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long k, f, t, joy, maxjoy = INT_MIN;
    int n, i;
    cin >> n >> k;

    for (i = 0; i < n; i++)
    {
        cin >> f >> t;

        joy = (t > k) ? (f - (t - k)) : f;
        if (joy > maxjoy)
        {
            maxjoy = joy;
        }
    }

    cout << maxjoy;
}