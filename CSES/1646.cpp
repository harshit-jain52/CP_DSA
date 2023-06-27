#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main()
{
    int n, q;
    cin >> n >> q;
    ll a[n], prefix_sum[n + 1];
    prefix_sum[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        prefix_sum[i + 1] = (prefix_sum[i] + a[i]);
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << (prefix_sum[r] - prefix_sum[l - 1]) << endl;
    }
}