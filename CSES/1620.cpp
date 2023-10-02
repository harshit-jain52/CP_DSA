#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

bool check(ll k[], ll t, ll time, int n)
{
    ll ct = 0;
    for (int i = 0; i < n; i++)
    {
        ct += time / k[i];
        if (ct >= t)
            break;
    }

    return (ct >= t);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    ll t;
    cin >> n >> t;

    ll k[n];
    for (int i = 0; i < n; i++)
    {
        cin >> k[i];
    }

    ll lo = 1, hi = (*min_element(k, k + n)) * t, mid;

    while (hi - lo > 1)
    {
        mid = (lo + hi) / 2;

        if (check(k, t, mid, n))
            hi = mid;
        else
            lo = mid + 1;
    }
    
    if (check(k, t, lo, n))
        cout << lo;
    else
        cout << hi;
}