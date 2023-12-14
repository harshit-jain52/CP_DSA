#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

void solve()
{
    ll n, x;
    cin >> n >> x;

    if ((n & x) != x)
    {
        cout << -1 << endl;
        return;
    }

    int leftmost = -1; // leftmost bit set in n, unset in x
    for (ll num = 0; num <= 60; num++)
    {
        ll tmp = 1LL << num;
        if ((tmp & n) != 0 && (tmp & x) == 0)
            leftmost = num;
    }

    if (leftmost == -1)
    {
        cout << n << endl;
        return;
    }

    for (ll num = leftmost - 1; num >= 0; num--)
    {
        ll tmp = 1LL << num;
        if ((x & tmp) != 0)
        {
            cout << -1 << endl;
            return;
        }
    }

    // x = n with some prefix bits set to 0

    int rightmost = -1; // rightmost set bit common to both
    for (ll num = 0; num <= 60; num++)
    {
        ll tmp = 1LL << num;
        if ((tmp & n) != 0 && (tmp & x) != 0)
        {
            rightmost = num;
            break;
        }
    }

    if (rightmost != -1 && rightmost <= leftmost + 1)
    {
        cout << -1 << endl;
        return;
    }

    ll tmp = 1LL << (leftmost + 1);
    cout << (n - ((tmp - 1) & n) + tmp) << endl;
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