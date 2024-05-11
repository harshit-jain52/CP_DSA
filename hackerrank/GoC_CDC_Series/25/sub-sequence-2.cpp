#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ans = 0;
    for (int p = 0; p < 31; p++)
    {
        int ct = 0;
        int pow = 1 << p;
        for (int i = 0; i < n; i++)
        {
            if (a[i] & pow)
                ct++;
        }
        ans = max(ans, ct);
    }
    cout << ans << endl;
}

int main()
{
    FASTIO
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}