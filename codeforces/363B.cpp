#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int prefix_sum[n + 1], h[n], i, min = 100 * k + 1, sum, j;

    for (i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    prefix_sum[0] = 0;

    for (i = 1; i < n + 1; i++)
    {
        prefix_sum[i] = h[i - 1] + prefix_sum[i - 1];
    }

    for (i = k; i < n + 1; i++)
    {
        sum = prefix_sum[i] - prefix_sum[i - k];
        if (sum < min)
        {
            min = sum;
            j = i - k;
        }
    }

    cout << j + 1;
}