#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int x[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    long long ans = 0;

    for (int i = 1; i < n; i++)
    {
        if (x[i] < x[i - 1])
        {
            ans += x[i - 1] - x[i];
            x[i] = x[i - 1];
        }
    }

    cout << ans;
}