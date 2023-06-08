#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;
    cin >> n;
    ll a[n];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);
    ll ct = a[n - 1];
    ll sup = 0;

    for (i = 0; i < n; i++)
    {
        sup += a[n - 1] - a[i];
    }

    ll add = 0;
    if (sup < a[n - 1])
    {
        ll x = a[n - 1] - sup;
        add = x / (n - 1) + (x % (n - 1) != 0);
    }

    cout << (ct + add);
}