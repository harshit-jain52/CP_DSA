#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

ll multiply(ll num, int n, ll x)
{
    ll tmp = 1;
    for (int i = 0; i < n; ++i)
    {
        tmp *= x;
        if (tmp > num)
            return tmp;
    }

    return tmp;
}

bool nthRoot(ll num, int n)
{
    ll lo = 1, hi = sqrt(num) + 10, mid;

    while (hi - lo > 1)
    {
        mid = (lo + hi) / 2;
        if (multiply(num, n, mid) <= num)
            lo = mid;
        else
            hi = mid - 1;
    }

    // cout << lo << " "<< hi << endl;;
    if (multiply(num, n, lo) == num)
        return true;
    if (multiply(num, n, hi) == num)
        return true;
    return false;
}

void solve()
{
    int n;
    cin >> n;
    ll a[n];
    ll p = 1;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        p *= a[i];
    }

    if (n == 1)
    {
        cout << "YES" << endl;
        return;
    }
    if (nthRoot(p, n))
        cout << "YES";
    else
        cout << "NO";
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}