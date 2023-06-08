#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, maxcount = 0, count;
    cin >> n;
    ll a[n];

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    count = 0;
    if (n <= 2)
    {
        cout << n;
    }
    else
    {
        for (i = 2; i < n; i++)
        {
            if (a[i] == a[i - 1] + a[i - 2])
            {
                count++;
                if (count > maxcount)
                {
                    maxcount = count;
                }
            }
            else
            {
                count = 0;
            }
        }

        cout << (maxcount + 2);
    }
}