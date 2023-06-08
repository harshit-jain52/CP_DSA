#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k, l, m, n, d, count, i;

    cin >> k >> l >> m >> n >> d;
    count = d;

    for (i = 1; i <= d; i++)
    {
        if (i % k && i % l && i % m && i % n)
        {
            count--;
        }
    }

    cout << count;

    return 0;
}