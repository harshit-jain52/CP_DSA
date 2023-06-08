#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    cin >> n >> t;
    int a[n];
    int sum[n + 1];
    sum[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum[i + 1] = sum[i] + a[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x = upper_bound(sum, sum + n + 1, t + sum[i]) - sum;
        ans = max(ans, x - i - 1);
    }

    cout << ans;
}