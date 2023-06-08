#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int a[n];

    ll a_sum[n + 1];
    a_sum[0] = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a_sum[i + 1] = a_sum[i] + a[i];
    }

    int m;
    cin >> m;
    while (m--)
    {
        ll q;
        cin >> q;
        cout << (lower_bound(a_sum, a_sum + n + 1, q) - a_sum) << '\n';
    }
}