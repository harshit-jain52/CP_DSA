#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k, i, j;
        cin >> n >> k;
        ll a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        ll sums[n + 1];
        sums[0] = 0;
        for (i = 0; i < n; i++)
        {
            sums[i + 1] = sums[i] + a[i];
        }

        ll maxsum = 0;
        for (i = 0, j = n - k - 1; i <= j&&j<n; i += 2,j++)
        {
            maxsum = max(maxsum, sums[j+1]-sums[i]);
        }

        cout << maxsum << endl;
    }
}