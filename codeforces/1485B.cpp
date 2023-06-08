#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, i;
    ll k;
    cin >> n >> q >> k;
    ll a[n], diffsum[n + 1];
    diffsum[0] = diffsum[1] = 0;

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (i = 1; i < n; i++)
    {
        diffsum[i + 1] = (a[i] - a[i - 1] - 1) + diffsum[i];
    }

    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        if (a[r - 1] > k)
        {
            cout << 0;
        }
        else
        {
            cout << (k - a[r - 1] + 2*(diffsum[r] - diffsum[l]) + a[l - 1] - 1) << endl;
        }
    }
}