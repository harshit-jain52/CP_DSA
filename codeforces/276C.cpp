#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, i;
    cin >> n >> q;
    ll a[n];
    vector<int> ct(n + 2, 0), ctsum(n + 1, 0);

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        ct[l]++;
        ct[r + 1]--;
    }

    for (i = 1; i <= n; i++)
    {
        ctsum[i] = ct[i] + ctsum[i - 1];
    }

    sort(ctsum.begin(), ctsum.end());
    sort(a, a + n);

    ll ans = 0;
    for (i = 0; i < n; i++)
    {
        ans += ctsum[i + 1] * a[i];
    }

    cout << ans;
}