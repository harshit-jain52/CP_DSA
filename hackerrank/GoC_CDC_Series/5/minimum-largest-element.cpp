#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int n;
ll a[N], k;

bool check(ll elem)
{
    ll ct = 0;
    for (int i = 0; i < n; i++)
        ct += (elem - a[i]) / (i + 1);

    return (ct >= k);
}
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll lo = *max_element(a, a + n), hi = *max_element(a, a + n) + k * n, mid;
    ll ans = hi;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (check(mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    cout << ans;
}