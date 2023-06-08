#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i;
    cin >> n;
    long long v[n];
    long long prefix_sum[n + 1], prefix_sum_sorted[n + 1];
    prefix_sum[0] = prefix_sum_sorted[0] = 0;

    for (i = 0; i < n; i++)
    {
        cin >> v[i];
        prefix_sum[i + 1] = prefix_sum[i] + v[i];
    }

    sort(v, v + n);

    for (i = 0; i < n; i++)
    {
        prefix_sum_sorted[i + 1] = prefix_sum_sorted[i] + v[i];
    }

    int m, type, l, r;
    cin >> m;

    while (m--)
    {
        cin >> type >> l >> r;

        if (type == 1)
        {
            cout << prefix_sum[r] - prefix_sum[l - 1];
        }
        else
        {
            cout << prefix_sum_sorted[r] - prefix_sum_sorted[l - 1];
        }
        cout << endl;
    }
}