#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
    FASTIO
    int n;
    ll x;
    cin >> n >> x;
    ll t[n];
    for (int i = 0; i < n; i++)
        cin >> t[i];

    int sz1 = n / 2, sz2 = n - sz1;
    vector<ll> half1, half2;

    for (int num = 0; num < (1 << sz1); num++)
    {
        ll sum = 0;
        for (int i = 0; i < sz1; i++)
        {
            if ((1 << i) & num)
                sum += t[i];
        }
        half1.push_back(sum);
    }

    for (int num = 0; num < (1 << sz2); num++)
    {
        ll sum = 0;
        for (int i = 0; i < sz2; i++)
        {
            if ((1 << i) & num)
                sum += t[sz1 + i];
        }
        half2.push_back(sum);
    }

    sort(half1.begin(), half1.end());
    sort(half2.begin(), half2.end());

    ll ways = 0;
    for (ll it : half1)
        ways += upper_bound(half2.begin(), half2.end(), x - it) - lower_bound(half2.begin(), half2.end(), x - it);

    cout << ways;
}