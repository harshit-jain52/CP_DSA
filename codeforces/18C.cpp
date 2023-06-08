#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;
    cin >> n;
    ll a[n], asum[n + 1];
    asum[0] = 0;

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        asum[i + 1] = asum[i] + a[i];
    }

    if (asum[n] & 1) // x&1 == x%2
    {
        cout << 0;
    }
    else
    {
        int count = 0;
        for (i = 1; i < n; i++)
        {
            if (asum[i] == (asum[n] >> 1)) // x>>1 == x/2
            {
                count++;
            }
        }
        cout << count;
    }
}