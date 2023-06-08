#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef unsigned long long int ulli;

int main()
{
    lli n, i;
    cin >> n;
    lli b[n], max_diff, max_b, min_b, maxb_count = 0, minb_count = 0, count;

    for (i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    sort(b, b + n);

    max_b = b[n - 1];
    min_b = b[0];
    max_diff = max_b - min_b;

    if (max_diff == 0)
    {
        count = n * (n - 1) / 2;
    }
    else
    {
        for (i = 0, minb_count = 0; i < n - 1; i++, minb_count++)
        {
            if (b[i] != min_b)
            {
                break;
            }
        }

        for (i = n - 1, maxb_count = 0; i > 0; i--, maxb_count++)
        {
            if (b[i] != max_b)
            {
                break;
            }
        }

        count = minb_count * maxb_count;
    }

    cout << max_diff << " " << count;
}